#ifndef STASIUN_H_INCLUDED
#define STASIUN_H_INCLUDED

using namespace std;

struct Stasiun {
    string id;
    string nama;
    string kabkot;
    string provinsi;
    int traffic;
};

typedef Stasiun StasiunInfoType;
typedef struct StasiunElement *StasiunAddress;

struct StasiunElement {
    StasiunInfoType info;
    StasiunAddress next;
};

struct StasiunList {
    StasiunAddress first;
};

void createStasiunList(StasiunList &stasiunList);
StasiunAddress createStasiunElement(StasiunInfoType data);

// A
void insertLastStasiun(StasiunList &stasiunList, StasiunAddress p);


// J
void findAllStasiun(StasiunList stasiunList);
// G
StasiunAddress findStasiunById(StasiunList stasiunList, string id);

// F
void deleteFirstStasiun(StasiunList &stasiunList, StasiunAddress &P);
void deleteLastStasiun(StasiunList &stasiunList, StasiunAddress &P);
void deleteAfterStasiun(StasiunList &stasiunList, StasiunAddress &P, StasiunAddress prec);
void deleteStasiunById(StasiunList &stasiunList, StasiunAddress &P, string id);





#endif // STASIUN_H_INCLUDED
