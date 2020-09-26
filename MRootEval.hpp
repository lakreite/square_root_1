#ifndef MRootEval_hpp_M
#define MRootEval_hpp_M
namespace MRootEval
{
    constexpr int Infinity_of_roots = -1;
    //! \brief сравнивает объект типа double с нулём
    //! \param[in] x - объект типа double
    //! \return
    //!     true  - если x равен 0
    //!     false - иначе
    inline auto IsZero(double x) -> bool;
    //! \brief Вычисляет корни уравнения ax^2 + bx + c = 0
    //! \param[in] a - коэффицент при x^2
    //! \param[in] b - коэффицент при x
    //! \param[in] c - свободный член
    //! \param[out] x1 - корень 1 (ссылка на double)
    //!      если D < 0 значение объекта не модифицирутся
    //!      если D = 0 то запишется -b / (2 * a)
    //!      если D > 0 запишется значение большего корня
    //!      (последнее только в случае, если следующий
    //!      параметр ссылка на другой объект)
    //! \param[out] x2 - корень 2 (ссылка на double)
    //!      если D < 0 значение объекта не модифицируется
    //!      если D = 0 запишется -b / (2 * a)
    //!      если D > 0 то:
    //!          1) если x1 и x2 ссылки на разные объекты:
    //!              x1 <- больший корень
    //!              x2 <- меньший корень
    //!          2) если x1 и x2 ссылки на один и тот же объект:
    //!              x1 <- меньший корень
    //!              x2 <- меньший корень
    //! \return 
    //!      MRootEval::Infinity_of_roots если корней бесконечно много
    //!      1 если корень 1 (даже если D = 0)
    //!      2 если корней 2
    auto SquareRootsEval(double a, double b, double c, double& x1, double& x2) -> int;
};
#endif
