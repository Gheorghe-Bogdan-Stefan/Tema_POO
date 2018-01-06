//
// Created by krucisatorul on 06.01.2018.
//

#include "Artist.h"

Artist::Artist() {
    albums = NULL;
    numberOfAlbums = 0;
}

Artist::Artist(string name, int age, Album *albums, int numberOfAlbums) {
    this->setName(name);
    this->setAge(age);
    this->albums = albums;
    this->numberOfAlbums = numberOfAlbums;
}

Artist::Artist(const Artist &artist) {
    albums = artist.albums;
    numberOfAlbums = artist.numberOfAlbums;
}

ostream &operator<<(ostream &os, const Artist &artist) {
    os << "Artist name: " << artist.getName() << endl;
    os << "Artist age: "  << artist.getAge() << endl;
    for (int i = 0; i < artist.numberOfAlbums; i++) {
        os << "Album number " << i + 1 << ": ";
        os << artist.albums[i];
    }
    return os;
}

istream &operator>>(istream &is, Artist &artist) {
    string auxiliarName;
    int auxiliarAge;
    cout << "Artist Name: ";
    is >> auxiliarName;
    artist.setName(auxiliarName);
    cout << "Artist Age: ";
    is >> auxiliarAge;
    artist.setAge(auxiliarAge);
    cout << "Number of Albums: ";
    is >> artist.numberOfAlbums;
    if (artist.albums != NULL) {
        delete []artist.albums;
    }
    artist.albums = new Album[artist.numberOfAlbums];
    for (int i = 0; i < artist.numberOfAlbums; i++) {
        cout << "Enter Album number " << i + 1 << endl;
        is   >> artist.albums[i];
        cout << endl;
    }
    return is;
}

Artist &Artist::operator =(const Artist &artist) {
    if (this->albums != NULL) {
        delete []this->albums;
    }
    this->numberOfAlbums = artist.numberOfAlbums;
    this->albums = new Album[artist.numberOfAlbums];
    for (int i = 0; i < this->numberOfAlbums; i++) {
        this->albums[i] = artist.albums[i];
    }
    return (*this);
}

void Artist::addAlbum(const Album &album) {
    Artist auxArtist;
    auxArtist.numberOfAlbums = this->numberOfAlbums + 1;
    auxArtist.albums = new Album[auxArtist.numberOfAlbums];
    for (int i = 0; i < auxArtist.numberOfAlbums - 1; i++) {
        auxArtist.albums[i] = this->albums[i];
    }
    auxArtist.albums[auxArtist.numberOfAlbums - 1] = album;
    (*this) = auxArtist;
}

void Artist::deleteAlbumAfterPosition(int positionForDelete) {
    Artist auxArtist;
    positionForDelete--;
    auxArtist.numberOfAlbums = this->numberOfAlbums - 1;
    auxArtist.albums = new Album[auxArtist.numberOfAlbums];
    for (int i = 0; i < positionForDelete; i++) {
        auxArtist.albums[i] = this->albums[i];
    }
    for (int i = positionForDelete + 1; i < this->numberOfAlbums; i++) {
        auxArtist.albums[i - 1] = this->albums[i];
    }
    (*this) = auxArtist;
}

void Artist::modifieAlbumAfterPosition(int positionForModifie) {
    Album auxAlbum;
    cout << endl;
    cout << "Enter the album for modifie: ";
    cin  >> auxAlbum;
    cout << endl;
    this->albums[positionForModifie - 1] = auxAlbum;
}

void Artist::modifieTrackAfterPositions(int albumPosition, int trackPosition) {
    Track auxTrack;
    cout << endl;
    cout << "Enter the track: ";
    cin  >> auxTrack;
    this->albums[albumPosition - 1].modifieTrack(auxTrack, trackPosition);
}

void Artist::sortAlbumsAfterYear() {
    Album swap;
    for (int i = 0; i < this->numberOfAlbums - 1; i++) {
        for (int j = 0; j < this->numberOfAlbums - i - 1; j++) {
            if (this->albums[j].getAppearanceYear() > this->albums[j + 1].getAppearanceYear()) {
                swap = this->albums[j];
                this->albums[j] = this->albums[j + 1];
                this->albums[j + 1] = swap;
            }
        }
    }
}

void Artist::sortAlbumsAfterYearAndName() {
    Album swap;
    char aux[100], aux1[100];
    string currentAlbumName, nextAlbumName;
    for (int i = 0; i < this->numberOfAlbums - 1; i++) {
        for (int j = 0; j < this->numberOfAlbums - i - 1; j++) {
            if (this->albums[j].getAppearanceYear() >=
                this->albums[j + 1].getAppearanceYear()) {
                if (this->albums[j].getAppearanceYear() !=
                    this->albums[j + 1].getAppearanceYear()) {
                    swap = this->albums[j];
                    this->albums[j] = this->albums[j + 1];
                    this->albums[j + 1] = swap;
                } else {
                    currentAlbumName = this->albums[j].getName();
                    nextAlbumName = this->albums[j + 1].getName();
                    int lengthCurrentAlbumName = currentAlbumName.length();
                    int lengthNextAlbumName = nextAlbumName.length();
                    for (int k = 0; k < lengthCurrentAlbumName; k++) {
                        aux[k] = currentAlbumName[k];
                    }
                    aux[lengthCurrentAlbumName] = '\0';
                    for (int k = 0; k < lengthNextAlbumName; k++) {
                        aux1[k] = nextAlbumName[k];
                    }
                    aux1[lengthNextAlbumName] = '\0';
                    if (strcmp(aux, aux1) > 0) {
                        swap = this->albums[j];
                        this->albums[j] = this->albums[j + 1];
                        this->albums[j + 1] = swap;
                    }
                }
            }
        }
    }
}

void Artist::deleteTrackAfterPositions(int albumPosition, int trackPosition) {
    this->albums[albumPosition - 1].deleteTrack(trackPosition);
}

void Artist::addTrackInAlbum(Track track, int albumPosition) {
    this->albums[albumPosition - 1].addTrack(track);
}


