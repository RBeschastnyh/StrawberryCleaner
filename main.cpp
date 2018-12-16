#include <iostream>
#include <tag.h>
#include <fileref.h>
#include <audioproperties.h>
#include <experimental/filesystem>

int main()
{
    int length = 0, choice = 0;
    char empty_space;
    std::string mp = ".mp3", ogg = ".ogg", flac = ".flac", path, artist_name, user_genre, name, type_name;
    std::cout << "Welcome to StrawberryCleaner! Choose an option:\n0) Delete files with low beatrate\n1) Delete all songs of an artist\n2) Delete all songs of selected genre\nHere: ";
    if(!(std::cin >> choice)){
        std::cerr << "Incorrect input";
        return 1;
    }
    switch (choice){
        case 0:{
            std::cout << "Write a path to a folder below:\n";
            std::cin >> empty_space;
            if(!(std::getline(std::cin, path))){
                std::cerr << "Incorrect input";
                return 1;
            }
            std::experimental::filesystem::path clear_path = path;
            for(auto& p : std::experimental::filesystem::directory_iterator(clear_path)){
                type_name = p.path().extension();
                name = p.path();
                if(type_name == mp || type_name == ogg || type_name == flac){
                    TagLib::FileRef f(name.c_str());
                    TagLib::Tag *tag = f.tag();
                    if(tag->artist() == artist_name) remove(name.c_str());
                }
            }
            break;
        }
        case 1:{
            std::cout << "Write a path to a folder below:\n";
            std::cin >> empty_space;
            if(!(std::getline(std::cin, path))){
                std::cerr << "Incorrect input";
                return 1;
            }
            std::cout << "Type a name of an annoying artist below:\n";
            std::cin >> artist_name;
            std::experimental::filesystem::path clear_path = path;
            for(auto& p : std::experimental::filesystem::directory_iterator(clear_path)){
                type_name = p.path().extension();
                name = p.path();
                if(type_name == mp || type_name == ogg || type_name == flac){
                    TagLib::FileRef f(name.c_str());
                    TagLib::Tag *tag = f.tag();
                    if(tag->artist() == artist_name) remove(name.c_str());
                }
            }
            break;
        }
        case 2:{
            std::cout << "Write a path to a folder below:\n";
            std::cin >> empty_space;
            if(!(std::getline(std::cin, path))){
                std::cerr << "Incorrect input";
                return 1;
            }
            std::cout << "Which genre should be deleted?\n";
            std::cin >> user_genre;
            std::experimental::filesystem::path clear_path = path;
            for(auto& p : std::experimental::filesystem::directory_iterator(clear_path)){
                type_name = p.path().extension();
                name = p.path();
                if(type_name == mp || type_name == ogg || type_name == flac){
                    TagLib::FileRef f(name.c_str());
                    TagLib::Tag *tag = f.tag();
                    if(tag->artist() == artist_name) remove(name.c_str());
                }
            }
            break;
        }
        default:{
            std::cerr << "Incorrect input" << "\n";
            return 1;
        }
    } 
}
