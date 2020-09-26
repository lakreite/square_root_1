#ifndef TestRoot_hpp_M
#define TestRoot_hpp_M

#include"MRootEval.hpp"
namespace TestSquare {
    using namespace MRootEval;
    //! \brief �������� ��� ������ ����������� ��������� � �� �����������
    struct TestRoot
    {
        double x1; //!< ������ ������
        double x2; //!< ������ ������
        int n;     //!< ���������� ������

        TestRoot();
        //! \brief ����� ����������� ��������
        //! \param[in] y1 - ������ 1
        //! \param[in] y2 - ������ 2
        //! \param[in] k  - ���������� ������
        TestRoot(double y1, double y2, int k);

        //! \brief ����������� �������� �� ������������
        //! ����������� ��������� ax^2 + bx + c = 0
        //! ����������� x1 � x2 NAN
        //! ����� �������� MRootEval::SquareRootsEval(..)
        //! \param[in] a - ���������� ��� x^2
        //! \param[in] b - ���������� ��� x
        //! \param[in] c - ��������� ����
        TestRoot(double a, double b, double c);

        //! \brief �������� == ��������� ��������
        //! \param[in] arg - ������ �� ��������
        //! \return
        //!     true  - ���� ��� ���� �������� �����
        //!     false - �����
        auto operator==(const TestRoot& arg) -> bool;


    };

    //! \brief ��������� ������������ ������� MRootEval::SquareRootsEval(..)
    auto testRootEval() -> void;
};
#endif
