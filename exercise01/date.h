#ifndef __DATE_H
#define __DATE_H


class Date
{
private:
	int day, month, year;

public:
    // Constructor
    Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {}

    // Destructor
    ~Date() {}

    // Member functions

    void showDate();
    void setDate(int d, int m, int y);
    int compareTo(const Date& other) const;

    bool operator<(const Date& other) const { return this->compareTo(other) == -1; }
};

#endif // !__DATE_H