//
// Created by krucisatorul on 06.01.2018.
//

#include "Album.h"

Album::Album() {
    name = '0';
    appearanceYear = 0;
    tracks = NULL;
    numberOfTracks = 0;
}

Album::Album(string name, int appearanceYear, Track *tracks,
             int numberOfTracks) {
    this->name = name;
    this->appearanceYear = appearanceYear;
    this->tracks = tracks;
    this->numberOfTracks = numberOfTracks;
}

Album::Album(const Album &album) {
    this->name = album.name;
    this->appearanceYear = album.appearanceYear;
    this->numberOfTracks = album.numberOfTracks;
    this->tracks = new Track[this->numberOfTracks];
    for (int i = 0; i < this->numberOfTracks; i++) {
        this->tracks[i] = album.tracks[i];
    }
}

Album &Album::operator =(const Album &album) {
    this->name = album.name;
    this->appearanceYear = album.appearanceYear;
    this->numberOfTracks = album.numberOfTracks;
    if (this->tracks != NULL) {
        delete []this->tracks;
    }
    this->tracks = new Track[this->numberOfTracks];
    for (int i = 0; i < this->numberOfTracks; i++) {
        this->tracks[i] = album.tracks[i];
    }
    return (*this);
}

ostream &operator <<(ostream &os, const Album &album) {
    os << "Name: " << album.name << " Appearance Year: " << album.appearanceYear;
    os << " Number of Tracks: " << album.numberOfTracks << endl;
    for (int i = 0; i < album.numberOfTracks; i++) {
        cout << "Track number " << i + 1 << ": ";
        cout << album.tracks[i];
    }
    return os;
}

istream &operator >>(istream &is, Album &album) {
    cout << "Album Name: " << endl;
    is >> album.name;
    cout << "Appearance Year: ";
    is >> album.appearanceYear;
    cout << "Album Number of Tracks: ";
    is >> album.numberOfTracks;
    if (album.tracks != NULL) {
        delete []album.tracks;
    }
    album.tracks = new Track[album.numberOfTracks];
    for (int i = 0; i < album.numberOfTracks; i++) {
        cout << "Track number " << i + 1 << ' ';
        is >> album.tracks[i];
        album.tracks[i].setPositionInAlbum(i + 1);
    }
    cout << endl;
    return is;
}

Album::~Album() {
    if (this->tracks != NULL) {
        delete []this->tracks;
        this->tracks = NULL;
    }
}

const string &Album::getName() const {
    return name;
}

void Album::setName(const string &name) {
    Album::name = name;
}

int Album::getAppearanceYear() const {
    return appearanceYear;
}

void Album::setAppearanceYear(int appearanceYear) {
    Album::appearanceYear = appearanceYear;
}

Track *Album::getTracks() const {
    return tracks;
}

void Album::setTracks(Track *tracks) {
    Album::tracks = tracks;
}

int Album::getNumberOfTracks() const {
    return numberOfTracks;
}

void Album::setNumberOfTracks(int numberOfTracks) {
    Album::numberOfTracks = numberOfTracks;
}

void Album::modifieTrack(const Track &track, int trackPosition) {
    for (int i = 0 ; i < this->numberOfTracks; i++) {
        if (this->tracks[i].getPositionInAlbum() == trackPosition) {
            this->tracks[i] = track;
            this->tracks[i].setPositionInAlbum(trackPosition);
        }
    }
}

void Album::deleteTrack(int trackPosition) {
    trackPosition--;
    Track *auxiliarTracks = new Track[this->numberOfTracks];
    for (int i = 0; i < this->numberOfTracks; i++) {
        auxiliarTracks[i] = this->tracks[i];
    }
    if (this->tracks != NULL) {
        delete []this->tracks;
    }
    this->tracks = new Track[this->numberOfTracks - 1];
    for (int i = 0; i < trackPosition; i++) {
        this->tracks[i] = auxiliarTracks[i];
    }
    for (int i = trackPosition + 1; i < this->numberOfTracks; i++) {
        this->tracks[i - 1] = auxiliarTracks[i];
        this->tracks[i - 1].setPositionInAlbum(i);
    }
    this->numberOfTracks--;
    delete []auxiliarTracks;
}

void Album::addTrack(Track track) {
    Track *auxTracks = new Track[this->numberOfTracks + 1];
    for(int i = 0; i < this->numberOfTracks; i++) {
        auxTracks[i] = this->tracks[i];
        auxTracks[i].setPositionInAlbum(i + 1);
    }
    auxTracks[this->numberOfTracks] = track;
    this->tracks = auxTracks;
    this->numberOfTracks++;
    this->tracks[this->numberOfTracks - 1].setPositionInAlbum(this->numberOfTracks);
}
