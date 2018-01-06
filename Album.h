//
// Created by krucisatorul on 06.01.2018.
//

#ifndef UNTITLED_ALBUM_H
#define UNTITLED_ALBUM_H

#include "Utility.h"
#include "Track.h"

class Album {
private:
    string name;
    int appearanceYear;
    Track *tracks;
    int numberOfTracks;
public:
    Album();

    Album(string name, int appearanceYear, Track *tracks, int numberOfTracks);

    Album(const Album &album);

    Album &operator =(const Album &album);

    friend ostream &operator <<(ostream &os, const Album &album);

    friend istream &operator >>(istream &is, Album &album);

    ~Album();

    const string &getName() const;

    void setName(const string &name);

    int getAppearanceYear() const;

    void setAppearanceYear(int appearanceYear);

    Track *getTracks() const;

    void setTracks(Track *tracks);

    int getNumberOfTracks() const;

    void setNumberOfTracks(int numberOfTracks);

    void modifieTrack(const Track &track, int trackPosition);

    void deleteTrack(int trackPosition);

    void addTrack(Track track);
};


#endif //UNTITLED_ALBUM_H
