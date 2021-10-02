
#include <variant>
#include <iostream>
using namespace std;

struct FilterBright{};
struct FilterDark{};
const int FILTERS = 1000;

template<class... Ts> struct overload : Ts... { using Ts::operator() ...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

constexpr std::variant<int> filter_pixel()
{
	std::variant<FilterBright, FilterDark> Filter{FilterDark()};    
    std::variant<int> pixel = 5;
    
    for(int j=0;j<FILTERS;++j)
    {
        std::visit (overload {
            [] (const FilterBright&, int& pixel ) { pixel+=1; },
            [](const FilterDark&, int& pixel) { pixel-=1;   },
        }, Filter, pixel);
    }

    return pixel;
}


int main()
{
    constexpr auto pixel = filter_pixel();
    std::cout << std::get<int>(pixel) << std::endl;
}
