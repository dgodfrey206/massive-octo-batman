#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human
{
    public:
        Human();
        ~Human();

        Human(int age, std::string name);
        Human(const Human& other);
        Human& operator=(Human rhs);

        friend void swap(Human& lhs, Human& rhs);

        template<class... Args>
        friend Human make_human(Args&&...);

        friend std::ostream& operator<<(std::ostream&, const Human&);
        friend std::istream& operator>>(std::istream&,       Human&);
    protected:
    private:
        int age;
        std::string name;
};

template<class... Args>
Human make_human(Args&&... args)
{
    return Human(std::forward<Args>(args)... );
}

#endif // HUMAN_H
