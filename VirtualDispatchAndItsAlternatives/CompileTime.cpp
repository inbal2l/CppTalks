#include <iostream>
#include <experimental/array>
#include <ctime>
#include <variant>

using namespace std;

const int PHOTO_SIZE = 100;

struct FilterBright{};
struct FilterDark{};

template <typename T, T Begin,  class Func, T ...Is>
constexpr void static_for_impl( Func &&f, std::integer_sequence<T, Is...> )
{
    ( f( std::integral_constant<T, Begin + Is>{ } ),... );
}

template <typename T, T Begin, T End, class Func >
constexpr void static_for( Func &&f )
{
    static_for_impl<T, Begin>( std::forward<Func>(f), std::make_integer_sequence<T, End - Begin>{ } );
}

struct CTAVisitActivate
{
    constexpr void operator()(const FilterBright& filter, int& pixel) { pixel+=1; }
    constexpr void operator()(const FilterDark&, int& pixel) { pixel-=1; }
};

constexpr std::variant<FilterBright, FilterDark> Filter{FilterBright()}; 

constexpr std::variant<int> filter_pixel(const int val)
{
    std::variant<int> var{val};
    std::visit (CTAVisitActivate(), Filter, var);    
    return var;
}

int main()
{
    std::variant<int> photoPixelAfter[PHOTO_SIZE] = {0};
    
    clock_t ACTVbegin = clock();
    
    static_for<int, 0, PHOTO_SIZE >( [&]( auto i)
    //for(int i=0 ; i<PHOTO_SIZE ; ++i)
    {
        constexpr auto ret = filter_pixel(0);
        photoPixelAfter[0] = std::get<int>(ret);
    });
    
    clock_t ACTVend = clock();
    cout << " Time is: " << ACTVend - ACTVbegin;

    return 0;
}
