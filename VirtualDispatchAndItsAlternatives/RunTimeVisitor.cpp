#include <ctime>
#include <variant>
#include <iostream>

using namespace std;
using Pixel =int;
const int PHOTO_SIZE = 10000;

struct FilterBright{};
struct FilterDark{};

struct VisitActivate
{
    void operator()(FilterBright& filter, Pixel& pixel) { pixel+=1; }
    void operator()(FilterDark&, Pixel& pixel) { pixel-=1; }
};

struct CTVisitActivate
{
    constexpr void operator()(const FilterBright& filter, Pixel& pixel) { pixel+=1; }
    constexpr void operator()(const FilterDark&, Pixel& pixel) { pixel-=1; }
};


int main()
{
    std::variant<int> photoV[PHOTO_SIZE];
    std::variant<FilterBright, FilterDark> filterV { FilterBright() };

    int Sj;
    clock_t Sbegin = clock();

    for (int Sj=0;Sj<PHOTO_SIZE;++Sj)
    { 
        std::visit(VisitActivate(), filterV, photoV[Sj]);
    }
    
    clock_t Send = clock();
    cout <<"Visitor implementation: "<< Send - Sbegin << endl;
}
