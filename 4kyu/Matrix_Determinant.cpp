#include <iostream>
#include <vector>
#include <cmath>

long long determinant(std::vector< std::vector<long long> > m) 
{
long long determ = 0;

  switch (m.size())
  {
  case 1:
    return m[0][0];
  case 2:
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
  default:
    for (int p = 0; p < m[0].size(); p++)
    {
      std::vector<std::vector< long long>> tmp;
      for (int i = 1; i < m.size(); i++)
      {
        std::vector<long long> row;
        for (int j = 0; j < m[i].size(); j++)
        {
          if (j != p)
          {
            row.push_back(m[i][j]);
          }
        }
        if (row.size() > 0)
          tmp.push_back(row);
      }
      determ = determ + m[0][p] * pow(-1, p) * determinant(tmp);
      
    }
    break;
  }
  return determ;
}
