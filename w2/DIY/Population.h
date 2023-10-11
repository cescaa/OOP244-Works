#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{
  struct Population
  {
    char *postal;
    int poulation;
  };
  void sort();
  bool load(Population &populations);
  bool load(const char filename[]);
  void display();
  void deallocateMemory();
}
#endif // SDDS_POPULATION_H_