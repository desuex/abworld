#include<iostream>
#include "TBufEC.h"
#include "TabWorldUnit.h"
#include "WorldUnit.h"
#include "ABKey.h"
#include "ABPoint.h"
#include "ABTriangle.h"
#include "ABLine.h"
#include "WorldZone.h"
#include "Export.h"

using namespace std;


int main(int argc, char *argv[]) {
    Export exp;
    exp.openFileToSave("output.txt");


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
    exp.writeLineHex("Signature", loadSignature);
    uint32_t loadVersion = buf.GetUINT32();
    if (loadVersion > version) {
        cerr << "Invalid version" << endl;
        return 1;
    }
    exp.writeLine("Version", loadVersion);
    ab_WorldRadius = buf.GetFloat();
    exp.writeLine("WorldRadius", ab_WorldRadius);
    ab_Camera_Radius = ab_WorldRadius + ab_Camera_RadiusDefaultFW;
    WorldUnit worldUnit = WorldUnit();
    worldUnit.LoadWorld(buf);

    exp.openObject("WorldUnit");
    TabWorldUnit *u = worldUnit.WorldUnit_First;
    while (u) {
        exp.openObject(u->FNo);
        exp.writeLine("FFileName", u->FFileName);
        exp.writeLine("FType", u->FType);
        exp.writeLine("FTimeOffset", u->FTimeOffset);
        exp.writeLine("FKeyGroup", u->FKeyGroup);
        exp.writeLine("FTimeLength", u->FTimeLength);
        exp.closeObject();
        u = u->FNext;
    }
    exp.closeObject();


    ABKey abKey = ABKey();
    abKey.KeyGroupList_LoadWorld(buf, worldUnit);
    exp.openObject("KeyGroupList"); //open KeyGroupList

    for (TKeyGroupList *const &i : abKey.KeyGroupList_List) {
        exp.openObject(i->FNo); //open TKeyGroupList
        exp.writeLine("ParentWorldUnit", static_cast<TabWorldUnit *>(i->FOwner)->FNo);
        exp.writeLine("FCur", i->FCur);
        exp.openObject("FList"); //open FList
        int counter = 0;
        for (auto const &k : i->FList) {
            exp.openObject(counter); //open TKeyGroup
            exp.writeLine("FName", k.FName);
            exp.closeObject(); //close TKeyGroup
        }
        exp.closeObject(); // close FList
        exp.closeObject(); // close TKeyGroupList
    }
    exp.closeObject(); // close KeyGroupList

    ABPoint abPoint = ABPoint();
    abPoint.Point_LoadWorld(buf, worldUnit);
    exp.openObject("Point"); //open Point
    TPointAB *p = abPoint.Point_First;
    while (p) {
        exp.openObject(p->FNo); //TPointAB
        exp.writeLine("FId", p->FId);
        exp.writeLine("FOrbit", p->FOrbit);
        exp.writeLine("FOrbitAngle", p->FOrbitAngle);
        exp.writeLine("FRadius", p->FRadius);
        exp.writeLine("FParent", p->FParent?p->FParent->FNo:p->FParentNum);

        exp.writeLine("FPortId", p->FPortId);
        exp.writeLine("FPortType", p->FPortType);
        exp.writeLine("FPortLink", p->FPortLink);

        exp.writeLine("FCopyPortId", p->FCopyPortId);
        exp.writeLine("FCopyPortType", p->FCopyPortType);
        exp.writeLine("FCopyPortLink", p->FCopyPortLink);
        exp.writeLine("FOwnerCount",(p->FOwnerCount));
        exp.openObject("FOwner"); //open FOwner
        for (TabWorldUnit *const &w : p->FOwner) {
            exp.writeLine("FNo", w->FNo);
        }
        exp.closeObject(); //close FOwner


        exp.openObject("FPos"); //open FPos
        exp.writeLine("x", (float) p->FPos.x);
        exp.writeLine("y", (float) p->FPos.y);
        exp.writeLine("z", (float) p->FPos.z);
        exp.closeObject(); //close FPos




        exp.closeObject(); //close TPointAB
        p = p->FNext;
    }

    exp.closeObject(); //close Point

    ABTriangle abTriangle = ABTriangle();
    abTriangle.Triangle_LoadWorld(buf, worldUnit, abKey, abPoint);

    exp.openObject("Triangle"); //open Triangle
    TTriangleAB *tr = abTriangle.Triangle_First;
    while (tr) {
        exp.openObject(tr->FNo); //TTriangleAB
        exp.writeLine("FTexture", tr->FTexture);
        exp.writeLine("FBackFace", tr->FBackFace);
        exp.writeLine("FOwner", tr->FOwner->FNo);
        exp.openObject("FV"); //start FV
        for (int i = 0; i < 3; i++) {
            exp.openObject(i); //start TTriangleUnitAB
            exp.writeLine("FVer", tr->FV[i]->FVer->FNo);
            exp.writeLine("FV", tr->FV[i]->FV);
            exp.writeLine("FU", tr->FV[i]->FU);
            exp.writeLine("WColor", tr->FV[i]->WColor);
            exp.closeObject(); // close TTriangleUnitAB
        }

        exp.closeObject(); //close FV

        //TODO: FGraph



        exp.closeObject(); //close TTriangleAB


        tr = tr->FNext;
    }
    exp.closeObject(); //Triangle



    ABLine abLine = ABLine();
    abLine.Line_LoadWorld(buf, abKey, abPoint, worldUnit);
    exp.openObject("Line"); //open Line
    TLineAB* li = abLine.Line_First;
    while (li) {
        exp.openObject(li->FNo); //TTriangleAB
        exp.writeLine("FVerStart",li->FVerStart->FNo);
        exp.writeLine("FVerEnd",li->FVerEnd->FNo);
        exp.writeLine("WColorStart", li->WColorStart);
        exp.writeLine("WColorEnd", li->WColorEnd);
        exp.writeLine("FShow", li->FShow);
        exp.writeLine("FStopLine", li->FStopLine);
        exp.writeLine("FOwner",li->FOwner->FNo);


        li = li->FNext;
        exp.closeObject(); //close TTriangleAB
    }
    exp.closeObject(); //close Line


    WorldZone worldZone = WorldZone();
    worldZone.Zone_LoadWorld(buf, ab_WorldRadius);
    exp.openObject("WorldZone"); //open WorldZone
    TabZone* tz = worldZone.Zone_First;
    while (tz) {
        exp.openObject(tz->FNo); //TabZone
        exp.writeLine("FOrb", tz->FOrb);
        exp.writeLine("FOrbAngle", tz->FOrbAngle);
        exp.writeLine("FRadiusAngle", tz->FRadiusAngle);
        exp.writeLine("FRadius", tz->FRadius);
        exp.writeLine("FType", tz->FType);
        exp.writeLine("FGraph", tz->FGraph);
        exp.writeLine("FHitpoints", tz->FHitpoints);
        exp.writeLine("FMass", tz->FMass);
        exp.writeLine("FDamage", tz->FDamage);
        exp.writeLine("FItem", tz->FItem);
        exp.writeLine("FItemFreq", tz->FItemFreq);
        exp.openObject("FPos"); //open FPos
        exp.writeLine("x", (float) tz->FPos.x);
        exp.writeLine("y", (float) tz->FPos.y);
        exp.writeLine("z", (float) tz->FPos.z);
        exp.closeObject(); //close FPos
        tz = tz->FNext;
        exp.closeObject(); //close TabZone

    }

    exp.closeObject();// close WorldZone
    //Point_ClearNo;
    //        Point_ListClear;
//    worldUnit.WorldUnit_CalcCenter();
    buf.Close();
    exp.Close();
    return 0;
}
