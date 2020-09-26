#ifndef MRootEval_hpp_M
#define MRootEval_hpp_M
namespace MRootEval
{
    constexpr int Infinity_of_roots = -1;
    //! \brief ���������� ������ ���� double � ����
    //! \param[in] x - ������ ���� double
    //! \return
    //!     true  - ���� x ����� 0
    //!     false - �����
    inline auto IsZero(double x) -> bool;
    //! \brief ��������� ����� ��������� ax^2 + bx + c = 0
    //! \param[in] a - ���������� ��� x^2
    //! \param[in] b - ���������� ��� x
    //! \param[in] c - ��������� ����
    //! \param[out] x1 - ������ 1 (������ �� double)
    //!      ���� D < 0 �������� ������� �� �������������
    //!      ���� D = 0 �� ��������� -b / (2 * a)
    //!      ���� D > 0 ��������� �������� �������� �����
    //!      (��������� ������ � ������, ���� ���������
    //!      �������� ������ �� ������ ������)
    //! \param[out] x2 - ������ 2 (������ �� double)
    //!      ���� D < 0 �������� ������� �� ��������������
    //!      ���� D = 0 ��������� -b / (2 * a)
    //!      ���� D > 0 ��:
    //!          1) ���� x1 � x2 ������ �� ������ �������:
    //!              x1 <- ������� ������
    //!              x2 <- ������� ������
    //!          2) ���� x1 � x2 ������ �� ���� � ��� �� ������:
    //!              x1 <- ������� ������
    //!              x2 <- ������� ������
    //! \return 
    //!      MRootEval::Infinity_of_roots ���� ������ ���������� �����
    //!      1 ���� ������ 1 (���� ���� D = 0)
    //!      2 ���� ������ 2
    auto SquareRootsEval(double a, double b, double c, double& x1, double& x2) -> int;
};
#endif
