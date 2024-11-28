// 3.Во примерот 
 
template<typename R, typename P>
R implicit_cast(const P& p) {
  return p;
}
 
int main() {
  int i = 1;
  float x = implicit_cast<float>(i);
  int j = implicit_cast<int>(x);
  
} //kraj na main
// замени ги R и P. Дали кодот се компајлира? Во што се состои проблемот? 

//odgovot

// ako gi zamenime R i P, toa ke dovede do nepravilno kastiranje ili nepogodni tipovi, 
// i kompajlerot ke pojavi greska zatoa sto ne moze avtomatski da napravi konverzija pomegu niv.
