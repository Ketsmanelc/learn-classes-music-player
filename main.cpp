#include <iostream>
#include <ctime>
#include <cstdlib>
class Track {
public:
    std::string name;
    //std::tm data;
    int length;

};


class Player{
    static const int capacity = 10;

    int numberPlayTrack = -1;

public:
    Track tracks[10];
    void Play() {
        if (numberPlayTrack == -1) {
            std::cout << "Enter track name: ";
            std::string UserInput;
            std::cin >> UserInput;
            for (int i = 0; i < capacity; i++) {
                if (UserInput == tracks[i].name) {
                    std::cout << "Play: " << tracks[i].name;
                    numberPlayTrack = i;
                }
            }
            if (numberPlayTrack < 0) std::cerr << "Track hasn't found!" << std::endl;
        }
    };

    void Pause() {
        if (numberPlayTrack != -1) {
            std::cout << "Paused: " << tracks[numberPlayTrack].name;
        }
    }

    void Next(){
        int tmp = std::rand() % capacity - 1;
        std::cout << "Play: " << tracks[tmp].name;
        numberPlayTrack = tmp;
    }

    void Stop(){
        if (numberPlayTrack != -1) {
            std::cout << "Stop: " << tracks[numberPlayTrack].name;
            numberPlayTrack = -1;
        }
    }
};

int main() {
    Player* player = new Player();
    std::string cmd;
    player->tracks[0].name = "Track_0";
    player->tracks[1].name = "Track_1";
    player->tracks[2].name = "Track_2";
    player->tracks[3].name = "Track_3";
    player->tracks[4].name = "Track_4";
    player->tracks[5].name = "Track_5";
    player->tracks[6].name = "Track_6";
    player->tracks[7].name = "Track_7";
    player->tracks[8].name = "Track_8";
    player->tracks[9].name = "Track_9";

    while (true) {
        std::cin >> cmd;
        if (cmd == "play") player->Play();
        else if (cmd == "pause") player->Pause();
        else if (cmd == "next") player->Next();
        else if (cmd == "stop") player->Stop();
        else if (cmd == "exit") return 0;
        else std::cerr << "Invalid command";
    }

    delete player;
    return 0;
}
