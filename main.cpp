#include<iostream>
#include<fstream>
#include <vector>
#include <filesystem>
#include "TBufEC.h"
#include "TabWorldUnit.h"
#include "WorldUnit.h"
#include "ABKey.h"
#include "ABPoint.h"
#include "ABTriangle.h"
#include "ABLine.h"
#include "WorldZone.h"

using namespace std;

struct Header {
    uint32_t marker;
    uint32_t version;
    float world_size;
    uint32_t elements_count;
};

void readPoints(ifstream &rf) {
    uint16_t total_objects;
    rf.read((char *) &total_objects, sizeof(total_objects));
    cout << "POINTS" << endl;
    cout << "total points: " << total_objects << endl;
    uint16_t filler16;
    uint64_t filler64;
    for (int obj = 0; obj < total_objects; obj++) {
        string guid;
        char c;
        for (int i = 0; i < 74; i++) {
            rf.read((char *) &c, sizeof(c));
            guid += c;
        }

        cout << "guid: " << guid << endl;

        rf.read((char *) &filler16, sizeof(filler16));
        cout << "filler16: " << filler16 << endl;
        float c_x;
        float c_y;
        float c_size;
        rf.read((char *) &c_x, sizeof(c_x));
        cout << "X: " << c_x << endl;
        rf.read((char *) &c_y, sizeof(c_y));
        cout << "Y: " << c_y << endl;
        rf.read((char *) &c_size, sizeof(c_size));
        cout << "Size: " << c_size << endl;

        rf.read((char *) &filler16, sizeof(filler16));
        cout << "filler16: " << filler16 << endl;
        rf.read((char *) &filler16, sizeof(filler16));
        cout << "filler16: " << filler16 << endl;
        string attribute;
        do {
            rf.read((char *) &c, sizeof(c) * 2);
            if (c == 0) {
                break;
            }
            attribute += c;


        } while (true);
        if (attribute.length() > 0) {
            cout << "attribute: " << attribute << endl;
            rf.read((char *) &filler16, sizeof(filler16));
            cout << "filler16: " << filler16 << endl;
        }

        rf.read((char *) &filler16, sizeof(filler16));
        cout << "filler16: " << filler16 << endl;
        rf.read((char *) &filler64, sizeof(filler64));
        cout << "filler64: " << filler64 << endl;
        rf.read((char *) &filler16, sizeof(filler16));
        cout << "filler16: " << filler16 << endl;
        rf.read((char *) &filler16, sizeof(filler16));
        cout << "filler16: " << filler16 << endl;
        rf.read((char *) &filler16, sizeof(filler16));
        cout << "filler16: " << filler16 << endl;

    }
}

Header readHead(ifstream &rf) {
    Header h{};
    rf.read((char *) &h.marker, sizeof(h.marker));
    rf.read((char *) &h.version, sizeof(h.version));
    rf.read((char *) &h.world_size, sizeof(h.world_size));
    rf.read((char *) &h.elements_count, sizeof(h.elements_count));
    cout << "header: " << h.marker << endl;
    cout << "version: " << h.version << endl;
    cout << "world size: " << h.world_size << endl;
    cout << "total elements: " << h.elements_count << endl;
    return h;
}

void readDataPaths(ifstream &rf, Header h) {
    string data_files[h.elements_count];
    for (int i = 0; i < h.elements_count; i++) {
        string data_path;
        char c;
        do {
            rf.read((char *) &c, sizeof(c) * 2);
            data_path += c;
            if (c == 0) {
                break;
            }

        } while (true);
        cout << "path: " << data_path << endl;
        data_files[i] = data_path;
        uint64_t filler;
        rf.read((char *) &filler, sizeof(filler));
        rf.read((char *) &filler, sizeof(filler));
    }
}

void readPointConfig(ifstream &rf) {
    uint16_t elements_count2;
    rf.read((char *) &elements_count2, sizeof(elements_count2));
    uint16_t filler;
    rf.read((char *) &filler, sizeof(filler));
    uint16_t some_number2;
    for (int i = 0; i < elements_count2 * 5; i++) {
        rf.read((char *) &some_number2, sizeof(some_number2));
    }
}

void readVertice(ifstream &rf) {
    uint16_t filler16;
    uint8_t filler8;
    uint16_t point_number;
    rf.read((char *) &filler8, sizeof(filler8));
    cout << "filler8: " << filler8 << endl;
    rf.read((char *) &point_number, 1);
    cout << "point #" << point_number << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;
    string diffuse;
    char c;
    char last = (char) 255;
    for (int i = 0; i < 255; i++) {
        rf.read((char *) &c, sizeof(c));
//        cout<<"char #"<<i<<": "<<c<<" num" <<(int)c<<endl;
        if (c != (char) 63) {
            diffuse += c;
        }

        if (c == 0 && last == 0) {
            break;
        }
        last = c;
    }
    cout << "diffuse: " << diffuse << endl;
//    rf.read((char *) &filler16, sizeof(filler16));
//    cout << "filler16: " << filler16 << endl;
//    rf.read((char *) &filler16, sizeof(filler16));
//    cout << "filler16: " << filler16 << endl;
//    rf.read((char *) &filler16, sizeof(filler16));
//    cout << "filler16: " << filler16 << endl;
//    rf.read((char *) &filler16, sizeof(filler16));
//    cout << "filler16: " << filler16 << endl;

//    rf.read((char *) &filler8, sizeof(filler8));
//    cout << "filler8: " << filler8 << endl;
}

void readPolygons(ifstream &rf) {
    uint16_t filler16;
    rf.read((char *) &filler16, sizeof(filler16));
    uint16_t polygonCount;
    rf.read((char *) &polygonCount, sizeof(polygonCount));
    cout << "polygon count: " << polygonCount << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    uint16_t polygon_number;
    rf.read((char *) &polygon_number, sizeof(polygon_number));
    cout << "polygon #" << polygon_number << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;
    rf.read((char *) &filler16, sizeof(filler16));
    cout << "filler16: " << filler16 << endl;


    readVertice(rf);
    readVertice(rf);
    readVertice(rf);


}


void readRaw(const string &filename) {

    ifstream rf(filename, ios::in | ios::binary);


    if (!rf) {
        cout << "Cannot open raw file!" << endl;
    }
    if (rf.is_open()) {
        Header h{};
        h = readHead(rf);
        readDataPaths(rf, h);

        readPointConfig(rf);
        readPoints(rf);
        readPolygons(rf);

        rf.close();
    }


}

TabWorldUnit *WorldUnit_First;
bool WorldUnit_First_initialized = false;
TabWorldUnit *WorldUnit_Last;
bool WorldUnit_Last_initialized = false;
TabWorldUnit el;

TabWorldUnit *WorldUnit_Add() {
    el = TabWorldUnit();
    if (WorldUnit_Last_initialized) {
        WorldUnit_Last->FNext = &el;
    }
    el.FPrev = WorldUnit_Last;
    WorldUnit_Last = &el;
    WorldUnit_Last_initialized = true;
    if (!WorldUnit_First_initialized) {
        WorldUnit_First = &el;
    }

    return &el;
}

void WorldUnit_LoadWorld(TBufEC &buf) {

    int i;
    int cnt;
//    TabWorldUnit el;
    cnt = buf.GetInteger();
    for (i = 0; i < cnt - i; i++) {
        el = *WorldUnit_Add();
        el.FNo = i;
        el.LoadWorld(buf);
    }

}

void KeyGroupList_LoadWorld(TBufEC &buf) {

}

void Point_LoadWorld(TBufEC &buf) {

}

void Triangle_LoadWorld(TBufEC &buf) {

}

void Line_LoadWorld(TBufEC &buf) {

}

void Zone_LoadWorld(TBufEC &buf) {

}


int main() {
    float ab_WorldRadius = 1000;

//    ab_Camera_Pos:TabPos;
    float ab_Camera_Radius = 2300;//1800;
    float ab_Camera_RadiusDefaultFW = 1300;//1800;
    float ab_Camera_RadiusMaxFW = 20000;
    float ab_Camera_Fov = 88;
    uint32_t signature = 0x57424152; //RABW
    uint32_t version = 3;
    TBufEC buf;
    buf.LoadFromFile("04_1_v00_new.raw");
    uint32_t loadSignature = buf.GetUINT32();
    if (loadSignature != signature) {
        cerr << "Invalid signature" << endl;
        return 1;
    }
    uint32_t loadVersion = buf.GetUINT32();
    if (loadVersion > version) {
        cerr << "Invalid version" << endl;
        return 1;
    }
    ab_WorldRadius = buf.GetFloat();
    ab_Camera_Radius = ab_WorldRadius + ab_Camera_RadiusDefaultFW;
    WorldUnit worldUnit = WorldUnit();
    worldUnit.LoadWorld(buf);
    ABKey abKey = ABKey();
    abKey.KeyGroupList_LoadWorld(buf, worldUnit);
    ABPoint abPoint = ABPoint();
    abPoint.Point_LoadWorld(buf, worldUnit);
    ABTriangle abTriangle = ABTriangle();
    abTriangle.Triangle_LoadWorld(buf, worldUnit, abKey, abPoint);
    ABLine abLine = ABLine();
    abLine.Line_LoadWorld(buf, abKey,abPoint, worldUnit);
    WorldZone worldZone = WorldZone();
    worldZone.Zone_LoadWorld(buf, ab_WorldRadius);
    //Point_ClearNo;
    //        Point_ListClear;
    worldUnit.WorldUnit_CalcCenter();
    buf.Close();

    return 0;
}
