//
// Created by krucisatorul on 06.01.2018.
//

#ifndef UNTITLED_ARTIST_H
#define UNTITLED_ARTIST_H

#include "Utility.h"
#include "Person.h"
#include "Album.h"

class Artist: public Person {
private:
    Album *albums;
    int numberOfAlbums;
public:
    Artist();

    Artist(string name, int age, Album *albums, int numberOfAlbums);

    Artist(const Artist &artist);

    friend ostream &operator <<(ostream &os, const Artist &artist);

    friend istream &operator >>(istream &is, Artist &artist);

    void addAlbum(const Album &album);

    Artist &operator =(const Artist &artist);

    void deleteAlbumAfterPosition(int positionForDelete);

    void modifieAlbumAfterPosition(int positionForModifie);

    void modifieTrackAfterPositions(int albumPosition, int trackPosition);

    void deleteTrackAfterPositions(int albumPosition, int trackPosition);

    void sortAlbumsAfterYear();

    void sortAlbumsAfterYearAndName();

    void addTrackInAlbum(Track track, int albumPosition);
};


#endif //UNTITLED_ARTIST_H
