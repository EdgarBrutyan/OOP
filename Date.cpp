struct Month {
private:
    int m_month;

public:
    explicit Month(int month)
        :m_month(month)
    {
        if (month > 12 || month <= 0)
        {
            throw("Invalid argument");
        }
    }

    static Month January() { return Month(1); }

    static Month February() { return Month(2); }

    static Month March() { return Month(3); }

    static Month April() { return Month(4); }

    static Month May() { return Month(5); }

    static Month June() { return Month(6); }

    static Month Jule() { return Month(7); }

    static Month August() { return Month(8); }

    static Month September() { return Month(9); }

    static Month Oktember() { return Month(10); }

    static Month November() { return Month(11); }

    static Month December() { return Month(12); }

    const int getMonth() const
    {
        return m_month;
    }
};

struct Day {
private:
    int m_day;

public:
     explicit Day(int day) 
        :m_day(day)
    {
        if (day > 30 || day <= 0)
        {
            throw("Invalid argument");
        }
    }

    const int getDay() const
    {
        return m_day;
    }
};

struct Year {
private:
    int m_year;

public:
    explicit Year(int year)
        :m_year(year)
    {
        if (year > 2100)
        {
            throw("Invalid argument");
        }
    }

    const int getYear() const
    {
        return m_year;
    }
};

class Date {
private:
    int _day;
    int _month;
    int _year;

public:
    explicit Date(const Day& day, const Month& month, const Year& year)
        : _day(day.getDay()), _month(month.getMonth()), _year(year.getYear())
    {}

    Date(const Date& date)
    {
        this->_day = date.Get_day();
        this->_month = date.Get_month();
        this->_year = date.Get_year();
    }

    int Get_year() const 
    {
        return _year;
    }

    int Get_month() const
    {
        return _month;
    }

    int Get_day() const
    {
        return _day;
    }
};