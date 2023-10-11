#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds
{
  class Food
  {
    char m_foodName[31];
    int m_cal;
    int m_time;
    char timeString[10];

    void
    setName(const char *name);

  public:
    void setEmpty();
    void getTimeString(int Time);
    bool isValid() const;
    void set(const char *name, int cal, int time);
    int getCals() const;
    void display() const;
  };
}

#endif // !SDDS_SUBJECT_H
