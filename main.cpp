#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <vector>
#include <iomanip>
class Track {
    std::string name;
    int duration = 0;
    std::tm creationTime;

public:
    std::string getName()
    {
        return name;
    }
    void setName(std::string newName)
    {
        name = newName;
    }
    int GetDuration()
    {
        return duration;
    }
    void SetDuration(int newValue)
    {
        if (newValue > 0) duration = newValue;
    }
    tm GetCreationTime()
    {
        return creationTime;
    }
    void SetCreationTime(std::tm* time)
    {
        creationTime = *time;
    }
};


class Player{
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
                    std::cout << "Play: " << tracks[i].getName() << " ";
                    std::cout << tracks[i].GetDuration() << "sec ";
                    std::time_t now = std::time(nullptr);
                    std::tm* time = std::localtime(&now);
                    time->tm_hour = tracks[i].GetCreationTime().tm_hour;
                    time->tm_min = tracks[i].GetCreationTime().tm_min;
                    time->tm_sec = tracks[i].GetCreationTime().tm_sec;
                    time->tm_year = tracks[i].GetCreationTime().tm_year;
                    time->tm_mon = tracks[i].GetCreationTime().tm_mon;
                    time->tm_year = tracks[i].GetCreationTime().tm_year;
                    std::cout << std::put_time(time, "%H:%M:%S %d/%m/%Y");
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
        Track newTrack;
        std::time_t now = std::time(nullptr);
        newTrack.SetCreationTime(std::localtime(&now));
        std::string nameTrack;
        std::cout << "Enter track name: ";
        std::cin >> nameTrack;
        newTrack.setName(nameTrack);
        int newTrackDuration;
        std::cout << "Enter track duration: ";
        std::cin >> newTrackDuration;
        newTrack.SetDuration(newTrackDuration);
        tracks.push_back(newTrack);
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
