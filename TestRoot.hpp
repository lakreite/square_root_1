#ifndef TestRoot_hpp_M
#define TestRoot_hpp_M

#include"MRootEval.hpp"
namespace TestSquare {
    using namespace MRootEval;
    //! \brief оболочка для корней квадратного уравнения с их количеством
    struct TestRoot
    {
        double x1; //!< первый корень
        double x2; //!< второй корень
        int n;     //!< количество корней

        TestRoot();
        //! \brief явный конструктор оболочки
        //! \param[in] y1 - корень 1
        //! \param[in] y2 - корень 2
        //! \param[in] k  - количество корней
        TestRoot(double y1, double y2, int k);

        //! \brief конструктор оболочки от коэффицентов
        //! квадратного уравнения ax^2 + bx + c = 0
        //! присваивает x1 и x2 NAN
        //! потом вызывает MRootEval::SquareRootsEval(..)
        //! \param[in] a - коэффицент при x^2
        //! \param[in] b - коэффицент при x
        //! \param[in] c - свободный член
        TestRoot(double a, double b, double c);

        //! \brief оператор == сравнения оболочек
        //! \param[in] arg - ссылка на оболочку
        //! \return
        //!     true  - если все поля оболочек равны
        //!     false - иначе
        auto operator==(const TestRoot& arg) -> bool;


    };

    //! \brief процедура тестирования функции MRootEval::SquareRootsEval(..)
    auto testRootEval() -> void;
};
#endif
