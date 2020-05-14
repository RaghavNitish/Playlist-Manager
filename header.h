#include <iostream>
#include <string>

class Song{
    public:
        std::string artist_name; //Stores the artist's name
        std::string song_name;  //Stores the song's name
};

class Playlist{
    public:
        int max_size; //Stores the maximum size of the playlist array
        int playlist_length; //Stores the present size of the playlist array
        Song* play_list_array; //Stores the playlist array

        Playlist();
        ~Playlist();
        void insert(std::string artist, std::string song);
        void play(int n);
        void erase(int n);
        void set_max(int size);
};
