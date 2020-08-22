//+-------------------------------------------------------------------------------+
//             ╔══════════════════════════════════════════════════╗
//             ║  Copyright (C) 2020 Paulo Victor Duarte          ║
//             ╚══════════════════════════════════════════════════╝
//+-------------------------------------------------------------------------------+
#include <ros/package.h>
#include <iostream>
#include <fstream>
#include <iomanip>      // std::setprecision & std::setw
#include <algorithm>    // std::count
#include <math.h>       // M_PI
using namespace std;

void outputLine( double x,double y,double z,double rx,double ry,double rz )
{
  //  cout.precision(17);
  //  std::cout.precision(2);
  //  std::cout.setf(std::ios::fixed);
  //  cout << setprecision(3) << fixed;
  cout << std::fixed << std::setprecision(2);
  cout << "outputLine :"
       << "x: "  << x << setw( 8 ) 
       << "y: "  << y << setw( 8 )
       << "z: "  << z << setw( 8 )
       << "rx: " << rx << setw( 8 ) 
       << "ry: " << ry << setw( 8 )
       << "rz: " << rz  
       << endl;
} // end function outputLine

int main()
{
//+-------------------------------------------------------------------------------+
  // Obter o endereco relativo do pacote ArmAgeddonRobot
  string RelativePath=ros::package::getPath("ArmAgeddonRobot");
  cout << RelativePath << endl;
//+-------------------------------------------------------------------------------+
  // Informar o numero de linhas do arquivo 
  std::ifstream inFile(RelativePath + "/arquivos/test2.txt"); 
  cout << "Numero de linhas: " << std::count(std::istreambuf_iterator<char>(inFile),std::istreambuf_iterator<char>(), '\n')+1 << endl;
  inFile.close();
//+-------------------------------------------------------------------------------+
  // ler o arquivo 
  ifstream inClientFile(RelativePath + "/arquivos/test2.txt");
  if(!inClientFile) {
    cout << "Cannot open input file.\n";
    return 1;
  }
  double x,y,z,rx,ry,rz;
  string descartar;
  while (!inClientFile.eof()){
    inClientFile >> descartar;
    inClientFile >> x ;
    inClientFile >> descartar;
    inClientFile >> y ;
    inClientFile >> descartar;
    inClientFile >> z ;
    inClientFile >> descartar;
    inClientFile >> rx;
    inClientFile >> descartar;
    inClientFile >> ry;
    inClientFile >> descartar;
    inClientFile >> rz;
    outputLine(x,y,z,rx,ry,rz);
  }
  
  inClientFile.close();

  return 0;
}