#ifndef MOVEMENT_H
#define MOVEMENT_H

class Movement {
  private:
    const float m_movement_speed_y_pos {4};
    const float m_movement_speed_y_neg {4};
    const float m_movement_speed_x_pos {4};
    const float m_movement_speed_x_neg {4};
    int movement_speed_multiplier { 1 };
    
    
  public:
    // Constructor
    Movement(const float move_speed_y_pos, const float move_speed_y_neg, const float move_speed_x_pos, const float move_speed_x_neg);
    const float* GetYPosMovementSpeed();
    const float* GetYNegMovementSpeed();
    const float* GetXPosMovementSpeed();
    const float* GetXNegMovementSpeed();
};

#endif 
