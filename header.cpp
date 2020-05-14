#include <iostream>
#include "header.h"
#include <string>

//Playlist class constructor
Playlist::Playlist(){
    playlist_length = 0;
}

//Playlist class destructor
Playlist::~Playlist(){
    delete[] play_list_array;
    play_list_array = NULL;
}

//Set max function
void Playlist::set_max(int size){
    max_size = size;

    //Creating the array that will store the playlist
    play_list_array = new Song [size];

    //Initialization
    for (int i = 0; i < max_size; i++){
        play_list_array[i].artist_name = "";
        play_list_array[i].song_name = "";
    }

    std::cout << "success" << std::endl;
}

//Adds a song (song title and artist) at the end of the playlist if song is not already in the list and the list is not full
void Playlist::insert(std::string artist, std::string song){

    //Step 1: Checking to see if the song already exists in the playlist array
    for (int i = 0; i < playlist_length; i++){
        if ((play_list_array[i].artist_name == artist) && (play_list_array[i].song_name == song)){
            std::cout << "can not insert " << song << ";" << artist << std::endl;
            return;
        }
    }

    //Step 2: Checking to see if the playlist array is at its maximum size
    if (playlist_length > max_size){
        std::cout << "can not insert " << song << ";" << artist << std::endl;
        return;
    }

    //Step 3: If the code reached this point, that means we can insert the song!
    play_list_array[playlist_length].artist_name = artist;
    play_list_array[playlist_length].song_name = song;
    playlist_length++;

    std::cout << "success" << std::endl;
}

//Plays song at position n
void Playlist::play(int n){
    //If the song doesn't exist at that location...
    if (play_list_array[n - 1].artist_name == "" and play_list_array[n - 1].song_name == ""){
        std::cout << "can not play " << n << std::endl;
    }

    //If the song exists at that location...
    else{
        std::cout << "played " << n << " " << play_list_array[n - 1].song_name << ";" << play_list_array[n - 1].artist_name << std::endl;
    }
}

//Erases song at position n
void Playlist::erase(int n){
    //If the song doesn't exist at that location...
    if (play_list_array[n - 1].artist_name == "" and play_list_array[n - 1].song_name == ""){
        std::cout << "can not erase " << n << std::endl;
    }

    //If the song exists at that location...
    else{
        for (int i = n; i < max_size; i++){
            play_list_array[i - 1].artist_name = play_list_array[i].artist_name;
            play_list_array[i - 1].song_name = play_list_array[i].song_name;
        }

        if ((playlist_length = max_size - 1)){
            play_list_array[max_size - 1].artist_name = "";
            play_list_array[max_size - 1].song_name = "";
        }

        playlist_length--;
        std::cout << "success" << std::endl;
    }
}
