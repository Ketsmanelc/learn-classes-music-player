#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <vector>
class Track {
    std::string name;

public:
    std::string getName()
    {
        return name;
    }
    void setName(std::string newName)
    {
        name = newName;
    }
};


class Player{
    Track newObject;
    int numberPlayTrack = -1;
    std::vector<Track> tracks;

public:

    void Play() {
        if (numberPlayTrack == -1) {
            std::cout << "Enter track name: ";
            std::string UserInput;
            std::cin >> UserInput;
            for (int i = 0; i < tracks.size(); i++) {
                if (UserInput == tracks[i].getName()) {
                    std::cout << "Play: " << tracks[i].getName();
                    numberPlayTrack = i;
                }
            }
            if (numberPlayTrack < 0) std::cerr << "Track hasn't found!" << std::endl;
        }
    };

    void Pause() {
        if (numberPlayTrack != -1) {
            std::cout << "Paused: " << tracks[numberPlayTrack].getName();
        }
    }

    void Next(){
        int tmp = std::rand() % tracks.size() - 1;
        std::cout << "Play: " << tracks[tmp].getName();
        numberPlayTrack = tmp;
    }

    void Stop(){
        if (numberPlayTrack != -1) {
            std::cout << "Stop: " << tracks[numberPlayTrack].getName();
            numberPlayTrack = -1;
        }
    }

    void Add() {
        std::cout << "Enter track name: ";
        std::string newTrack;
        std::cin >> newTrack;
        //std::getline (std::cin, newTrack);
        tracks.push_back(newObject);
        tracks[tracks.size() - 1].setName(newTrack) ;

    }

};

int main() {
    Player* player = new Player();
    std::string cmd;

       while (true) {
        std::cin >> cmd;
        if (cmd == "play") player->Play();
        else if (cmd == "pause") player->Pause();
        else if (cmd == "next") player->Next();
        else if (cmd == "stop") player->Stop();
        else if (cmd == "add") player->Add();
        else if (cmd == "exit") break;
        else std::cerr << "Invalid command";
    }

    delete player;
    return 0;
}
