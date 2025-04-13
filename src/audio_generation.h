#ifndef AUDIO_GENERATION_H
#define AUDIO_GENERATION_H

#include <math.h>

class SineAudio {
  private:
  static constexpr double m_pi_double { 6.283185307 };
  static constexpr double m_sample_rate { 44100 };
  
  const double m_time { 1 };
  const double m_frequency { 440 };
  const double m_amplitude { 1 };
  
  private:
  short generateSineWave();
    
};

#endif // !AUDIO_GENERATION_H
