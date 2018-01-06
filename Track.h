//
// Created by krucisatorul on 06.01.2018.
//

#ifndef UNTITLED_TRACK_H
#define UNTITLED_TRACK_H

#include <ostream>
#include "Utility.h"

class Track {
private:
    string name;
    int positionInAlbum;
public:
    Track();

    Track(string name, int positionInAlbum);

    Track(const Track &track);

    Track &operator =(const Track &track);

    friend ostream &operator <<(ostream &os, const Track &track);

    friend istream &operator >>(istream &is, Track &track);

    const string &getName() const;

    void setName(const string &name);

    int getPositionInAlbum() const;

    void setPositionInAlbum(int positionInAlbum);

};


#endif //UNTITLED_TRACK_H
