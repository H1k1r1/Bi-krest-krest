//task1
#include <iostream>
#include <vector>
#include <deque>

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> sequence[i];
    }

    std::deque<int> window;

    for (int i = 0; i < k; ++i)
    {
        while (!window.empty() && sequence[i] <= sequence[window.back()])
        {
            window.pop_back();
        }
        window.push_back(i);
    }

    std::cout << sequence[window.front()] << std::endl;

    for (int i = k; i < n; ++i)
    {
        while (!window.empty() && window.front() <= i - k)
        {
            window.pop_front();
        }

        while (!window.empty() && sequence[i] <= sequence[window.back()])
        {
            window.pop_back();
        }
        window.push_back(i);
        std::cout << sequence[window.front()] << std::endl;
    }

    return 0;
}
//task2
#include <iostream>
#include <vector>
#include <string>

int main()
{
    int M, N;
    std::cin >> M >> N;

    std::string firstWord;
    std::vector<int> firstVector(N);
    std::cin >> firstWord;
    for (int& x: firstVector)
    {
        std::cin >> x;
    }

    std::vector<std::string> words(M - 1);
    std::vector<int> scalarProducts(M - 1);

    for (int i = 0; i < M - 1; ++i)
    {
        std::cin >> words[i];
        std::vector<int> vec(N);
        for (int j = 0; j < N; ++j)
        {
            std::cin >> vec[j];
        }

        int product = 0;
        for (int j = 0; j < N; ++j)
        {
            product += vec[j] * firstVector[j];
        }
        scalarProducts[i] = product;
    }

    int maxProduct = scalarProducts[0];
    for (int product: scalarProducts)
    {
        if (product > maxProduct)
        {
            maxProduct = product;
        }
    }

    for (int i = 0; i < M - 1; ++i)
    {
        if (scalarProducts[i] == maxProduct)
        {
            std::cout << words[i] << std::endl;
        }
    }

    return 0;
}
//task3
#include <iostream>

#include <cmath>

#include <complex.h>

class Complex
{
public:
    Complex(double re = 0.0, double im = 0.0) : re_(re), im_(im) {}

    double Re() const { return re_; }
    double Im() const { return im_; }

    Complex operator+() const { return *this; }
    Complex operator-() const { return Complex(-re_, -im_); }

    Complex operator+(const Complex& other) const
    {
        return Complex(re_ + other.re_, im_ + other.im_);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(re_ - other.re_, im_ - other.im_);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + im_ * other.re_);
    }

    Complex operator/(const Complex& other) const
    {
        double denominator = other.re_ * other.re_ + other.im_ * other.im_;
        return Complex((re_ * other.re_ + im_ * other.im_) / denominator,
                       (im_ * other.re_ - re_ * other.im_) / denominator);
    }

    Complex operator+(double rhs) const
    {
        return Complex(re_ + rhs, im_);
    }
    friend Complex operator+(double lhs, const Complex& rhs);

    Complex operator-(double rhs) const
    {
        return Complex(re_ - rhs, im_);
    }
    friend Complex operator-(double lhs, const Complex& rhs);

    Complex operator*(double rhs) const
    {
        return Complex(re_ * rhs, im_ * rhs);
    }
    friend Complex operator*(double lhs, const Complex& rhs);

    Complex operator/(double rhs) const
    {
        return Complex(re_ / rhs, im_ / rhs);
    }
    friend Complex operator/(double lhs, const Complex& rhs);

    bool operator==(const Complex& other) const
    {
        return re_ == other.re_ && im_ == other.im_;
    }

    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }

private:
    double re_, im_;
};

Complex operator+(double lhs, const Complex& rhs)
{
    return Complex(lhs + rhs.Re(), rhs.Im());
}

Complex operator-(double lhs, const Complex& rhs)
{
    return Complex(lhs - rhs.Re(), -rhs.Im());
}

Complex operator*(double lhs, const Complex& rhs)
{
    return Complex(lhs * rhs.Re(), lhs * rhs.Im());
}

Complex operator/(double lhs, const Complex& rhs)
{
    double denominator = rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im();
    return Complex(lhs * rhs.Re() / denominator, -lhs * rhs.Im() / denominator);
}

double abs(const Complex& x)
{
    return std::sqrt(x.Re() * x.Re() + x.Im() * x.Im());
}
//task4
#include <iostream>
#include <numeric>

class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        int gcd = std::gcd(numerator, denominator);
        this->numerator_ = numerator / gcd;
        this->denominator_ = denominator / gcd;
        if (this->denominator_ < 0)
        {
            this->numerator_ = -this->numerator_;
            this->denominator_ = -this->denominator_;
        }
    }

    Rational& operator+=(const Rational& rhs)
    {
        int num = numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_;
        int denom = denominator_ * rhs.denominator_;
        *this = Rational(num, denom);
        return *this;
    }

    Rational& operator-=(const Rational& rhs)
    {
        int num = numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_;
        int denom = denominator_ * rhs.denominator_;
        *this = Rational(num, denom);
        return *this;
    }

    Rational& operator*=(const Rational& rhs)
    {
        int num = numerator_ * rhs.numerator_;
        int denom = denominator_ * rhs.denominator_;
        *this = Rational(num, denom);
        return *this;
    }

    Rational& operator/=(const Rational& rhs)
    {
        if (rhs.numerator_ == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        int num = numerator_ * rhs.denominator_;
        int denom = denominator_ * rhs.numerator_;
        *this = Rational(num, denom);
        return *this;
    }

    Rational operator+() const
    {
        return *this;
    }

    Rational operator-() const
    {
        return Rational(-numerator_, denominator_);
    }

    bool operator==(const Rational& rhs) const
    {
        return numerator_ == rhs.numerator_ && denominator_ == rhs.denominator_;
    }

    bool operator!=(const Rational& rhs) const
    {
        return !(*this == rhs);
    }

    Rational& operator++()
    {
        numerator_ += denominator_;
        return *this;
    }

    Rational operator++(int)
    {
        Rational temp = *this;
        ++(*this);
        return temp;
    }

    Rational& operator--()
    {
        numerator_ -= denominator_;
        return *this;
    }

    Rational operator--(int)
    {
        Rational temp = *this;
        --(*this);
        return temp;
    }

    int numerator() const
    {
        return numerator_;
    }

    int denominator() const
    {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) += rhs;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) -= rhs;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) *= rhs;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) /= rhs;
}
//task5
#include <iostream>
#include <vector>

using std::vector;

class Minesweeper
{
private:
    size_t M, N;
    vector<vector<int>> Table;

public:
    Minesweeper(size_t m, size_t n) : M(m), N(n)
    {
        Table = vector<vector<int>>(M, vector<int>(N, 0));
    }

    size_t Rows() const
    {
        return M;
    }

    size_t Columns() const
    {
        return N;
    }

    void SetMine(size_t i, size_t j)
    {
        if (i < M && j < N)
        {
            Table[i][j] = -1;
        }
    }

    int operator()(size_t i, size_t j) const
    {
        if (i < M && j < N)
        {
            return Table[i][j];
        }
        return -2;
    }

    void CheckForMinesAround()
    {
        for (size_t i = 0; i < M; ++i)
        {
            for (size_t j = 0; j < N; ++j)
            {
                if (Table[i][j] != -1)
                {
                    Table[i][j] = minesAround(i, j);
                }
            }
        }
    }

private:
    int minesAround(size_t i, size_t j) const
    {
        int counter = 0;
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (0 <= i + dx && i + dx < M &&
                    0 <= j + dy && j + dy < N &&
                    Table[i + dx][j + dy] == -1)
                {
                    ++counter;
                }
            }
        }
        return counter;
    }
};

std::ostream& operator<<(std::ostream& out, const Minesweeper& ms)
{
    for (size_t i = 0; i < ms.Rows(); ++i)
    {
        for (size_t j = 0; j < ms.Columns(); ++j)
        {
            if (ms(i, j) == -1)
                out << '*';
            else
                out << ms(i, j);
        }
        out << "\n";
    }
    return out;
}
//////////////////////////////////////////////////////////