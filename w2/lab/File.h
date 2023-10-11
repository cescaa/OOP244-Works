#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   // TODO: Declare read prototypes
   bool read(int &m_empNo);
   bool read(double &m_salary);
   bool read(char *m_name);

}
#endif // !SDDS_FILE_H_
