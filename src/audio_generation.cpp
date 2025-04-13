#include "audio_generation.h"
#include <cmath>

short SineAudio::generateSineWave() {
  short sine_result;
  double ticks_per_second { m_sample_rate / m_frequency };
  double cycles { m_time / ticks_per_second };
  double radians { m_pi_double * cycles };
  double amplitude { 32767 * m_amplitude };
  return sine_result = amplitude * sin(radians); 
};

