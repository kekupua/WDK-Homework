class item {
private:
  int cost;
public:
  item() {cost = 1;}
  int getCost(){ return cost; }
  void setCost(int c){ cost = c; return;}
};

class food : public item {
private:
  int hungerValue;
  int moodValue;
  int healthValue;

public:
  food(int type){
    if(type == 1){ // Medicine
      healthValue = 1; moodValue = 0; healthValue = 0;
    }
    else if(type == 2){ // Bread
      hungerValue = 1; hungerValue = 0; moodValue = 0;
    }
    else if(type == 3){ // Candy
      moodValue = 1; healthValue = -1; hungerValue = 0;
    }
  }

  int getHunger(){ return hungerValue; }
  int getMood(){ return moodValue; }
  int getHealth(){ return healthValue; }
  void setHunger(int h){ hungerValue = h; return;}
  void setMood(int m){ moodValue = m; return;}
  void setHealth(int h){ healthValue = h; return;}
};
