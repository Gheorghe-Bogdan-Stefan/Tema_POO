//
// Created by krucisatorul on 06.01.2018.
//

#include "Track.h"

ostream &operator<<(ostream &os, const Track &track) {
    os << "Track Name: " << track.name << " Position in Album: "
       << track.positionInAlbum  << endl;
    return os;
}

Track::Track() {
    name = '0';
    positionInAlbum = 0;
}

Track::Track(string name, int positionInAlbum): name(name),
                                                positionInAlbum(positionInAlbum)
                                                {}

Track::Track(const Track &track) {
    name            = track.name;
    positionInAlbum = track.positionInAlbum;
}

Track &Track::operator =(const Track &track) {
    name            = track.name;
    positionInAlbum = track.positionInAlbum;
    return (*this);
}

istream &operator >>(istream &is, Track &track) {
    cout << "Track name: ";
    is >> track.name;
    return is;
}

const string &Track::getName() const {
    return name;
}

void Track::setName(const string &name) {
    Track::name = name;
}

int Track::getPositionInAlbum() const {
    return positionInAlbum;
}

void Track::setPositionInAlbum(int positionInAlbum) {
    Track::positionInAlbum = positionInAlbum;
}
