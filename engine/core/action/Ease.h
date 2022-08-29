//
// (c) 2021 Eduardo Doria.
//

#ifndef EASE_H
#define EASE_H

#define _USE_MATH_DEFINES
#include <math.h>

namespace Supernova {

    enum class EaseType{
        LINEAR,
        QUAD_IN,
        QUAD_OUT,
        QUAD_IN_OUT,
        CUBIC_IN,
        CUBIC_OUT,
        CUBIC_IN_OUT,
        QUART_IN,
        QUART_OUT,
        QUART_IN_OUT,
        QUINT_IN,
        QUINT_OUT,
        QUINT_IN_OUT,
        SINE_IN,
        SINE_OUT,
        SINE_IN_OUT,
        EXPO_IN,
        EXPO_OUT,
        EXPO_IN_OUT,
        CIRC_IN,
        CIRC_OUT,
        CIRC_IN_OUT,
        ELASTIC_IN,
        ELASTIC_OUT,
        ELASTIC_IN_OUT,
        BACK_IN,
        BACK_OUT,
        BACK_IN_OUT,
        BOUNCE_IN,
        BOUNCE_OUT,
        BOUNCE_IN_OUT
    };

    class Ease {

        public:

        static inline float linear(float time){
            return time;
        }

        static inline float easeInQuad(float time){
            return time * time;
        }

        static inline float easeOutQuad(float time){
            return time * (2 - time);
        }

        static inline float easeInOutQuad(float time){
            if ((time *= 2) < 1) {
                return 0.5 * time * time;
            }

            time--;
            return - 0.5 * (time * (time - 2) - 1);
        }

        static inline float easeInCubic(float time){
            return time * time * time;
        }

        static inline float easeOutCubic(float time){
            time--;
            return time * time * time + 1;
        }

        static inline float easeInOutCubic(float time){
            if ((time *= 2) < 1) {
                return 0.5 * time * time * time;
            }
            time -= 2;
            return 0.5 * (time * time * time + 2);
        }

        static inline float easeInQuart(float time){
            return time * time * time * time;
        }

        static inline float easeOutQuart(float time){
            time--;
            return 1 - (time * time * time * time);
        }

        static inline float easeInOutQuart(float time){
            if ((time *= 2) < 1) {
                return 0.5 * time * time * time * time;
            }
            time -= 2;
            return - 0.5 * (time * time * time * time - 2);
        }

        static inline float easeInQuint(float time){
            return time * time * time * time * time;
        }

        static inline float easeOutQuint(float time){
            time--;
            return time * time * time * time * time + 1;
        }

        static inline float easeInOutQuint(float time){
            if ((time *= 2) < 1) {
                return 0.5 * time * time * time * time * time;
            }

            time -= 2;
            return 0.5 * (time * time * time * time * time + 2);
        }

        static inline float easeInSine(float time){
            return 1 - cos(time * M_PI / 2);
        }

        static inline float easeOutSine(float time){
            return sin(time * M_PI / 2);
        }

        static inline float easeInOutSine(float time){
            return 0.5 * (1 - cos(M_PI * time));
        }

        static inline float easeInExpo(float time){
            return time == 0 ? 0 : pow(1024, time - 1);
        }

        static inline float easeOutExpo(float time){
            return time == 1 ? 1 : 1 - pow(2, - 10 * time);
        }

        static inline float easeInOutExpo(float time){
            if (time == 0) {
                return 0;
            }

            if (time == 1) {
                return 1;
            }

            if ((time *= 2) < 1) {
                return 0.5 * pow(1024, time - 1);
            }

            return 0.5 * (- pow(2, - 10 * (time - 1)) + 2);
        }

        static inline float easeInCirc(float time){
            return 1 - sqrt(1 - time * time);
        }

        static inline float easeOutCirc(float time){
            time--;
            return sqrt(1 - (time * time));
        }

        static inline float easeInOutCirc(float time){
            if ((time *= 2) < 1) {
                return - 0.5 * (sqrt(1 - time * time) - 1);
            }

            time -= 2;
            return 0.5 * (sqrt(1 - time * time) + 1);
        }

        static inline float easeInElastic(float time){
            if (time == 0) {
                return 0;
            }

            if (time == 1) {
                return 1;
            }

            return -pow(2, 10 * (time - 1)) * sin((time - 1.1) * 5 * M_PI);
        }

        static inline float easeOutElastic(float time){
            if (time == 0) {
                return 0;
            }

            if (time == 1) {
                return 1;
            }

            return pow(2, -10 * time) * sin((time - 0.1) * 5 * M_PI) + 1;
        }

        static inline float easeInOutElastic(float time){
            if (time == 0) {
                return 0;
            }

            if (time == 1) {
                return 1;
            }

            time *= 2;

            if (time < 1) {
                return -0.5 * pow(2, 10 * (time - 1)) * sin((time - 1.1) * 5 * M_PI);
            }

            return 0.5 * pow(2, -10 * (time - 1)) * sin((time - 1.1) * 5 * M_PI) + 1;
        }

        static inline float easeInBack(float time){
            float s = 1.70158;

            return time * time * ((s + 1) * time - s);
        }

        static inline float easeOutBack(float time){
            float s = 1.70158;

            time--;
            return time * time * ((s + 1) * time + s) + 1;
        }

        static inline float easeInOutBack(float time){
            float s = 1.70158 * 1.525;

            if ((time *= 2) < 1) {
                return 0.5 * (time * time * ((s + 1) * time - s));
            }

            time -= 2;
            return 0.5 * (time * time * ((s + 1) * time + s) + 2);
        }

        static inline float easeOutBounce(float time){
            if (time < (1 / 2.75)) {
                return 7.5625 * time * time;
            } else if (time < (2 / 2.75)) {
                time -= (1.5 / 2.75);
                return 7.5625 * time * time + 0.75;
            } else if (time < (2.5 / 2.75)) {
                time -= (2.25 / 2.75);
                return 7.5625 * time * time + 0.9375;
            } else {
                time -= (2.625 / 2.75);
                return 7.5625 * time * time + 0.984375;
            }
        }

        static inline float easeInBounce(float time){
            return 1 - easeOutBounce(1 - time);
        }

        static inline float easeInOutBounce(float time){
            if (time < 0.5) {
                return easeInBounce(time * 2) * 0.5;
            }

            return easeOutBounce(time * 2 - 1) * 0.5 + 0.5;
        }

        static inline Function<float(float)> getFunction(EaseType functionType){
            if (functionType == EaseType::LINEAR){
                return Function<float(float)>(Ease::linear);
            }else if(functionType == EaseType::QUAD_IN){
                return Function<float(float)>(Ease::easeInQuad);
            }else if(functionType == EaseType::QUAD_OUT){
                return Function<float(float)>(Ease::easeOutQuad);
            }else if(functionType == EaseType::QUAD_IN_OUT){
                return Function<float(float)>(Ease::easeInOutQuad);
            }else if(functionType == EaseType::CUBIC_IN){
                return Function<float(float)>(Ease::easeInCubic);
            }else if(functionType == EaseType::CUBIC_OUT){
                return Function<float(float)>(Ease::easeOutCubic);
            }else if(functionType == EaseType::CUBIC_IN_OUT){
                return Function<float(float)>(Ease::easeInOutCubic);
            }else if(functionType == EaseType::QUART_IN){
                return Function<float(float)>(Ease::easeInQuart);
            }else if(functionType == EaseType::QUART_OUT){
                return Function<float(float)>(Ease::easeOutQuart);
            }else if(functionType == EaseType::QUART_IN_OUT){
                return Function<float(float)>(Ease::easeInOutQuart);
            }else if(functionType == EaseType::QUINT_IN){
                return Function<float(float)>(Ease::easeInQuint);
            }else if(functionType == EaseType::QUINT_OUT){
                return Function<float(float)>(Ease::easeOutQuint);
            }else if(functionType == EaseType::QUINT_IN_OUT){
                return Function<float(float)>(Ease::easeInOutQuint);
            }else if(functionType == EaseType::SINE_IN){
                return Function<float(float)>(Ease::easeInSine);
            }else if(functionType == EaseType::SINE_OUT){
                return Function<float(float)>(Ease::easeOutSine);
            }else if(functionType == EaseType::SINE_IN_OUT){
                return Function<float(float)>(Ease::easeInOutSine);
            }else if(functionType == EaseType::EXPO_IN){
                return Function<float(float)>(Ease::easeInExpo);
            }else if(functionType == EaseType::EXPO_OUT){
                return Function<float(float)>(Ease::easeOutExpo);
            }else if(functionType == EaseType::EXPO_IN_OUT){
                return Function<float(float)>(Ease::easeInOutExpo);
            }else if(functionType == EaseType::CIRC_IN){
                return Function<float(float)>(Ease::easeInCirc);
            }else if(functionType == EaseType::CIRC_OUT){
                return Function<float(float)>(Ease::easeOutCirc);
            }else if(functionType == EaseType::CIRC_IN_OUT){
                return Function<float(float)>(Ease::easeInOutCirc);
            }else if(functionType == EaseType::ELASTIC_IN){
                return Function<float(float)>(Ease::easeInElastic);
            }else if(functionType == EaseType::ELASTIC_OUT){
                return Function<float(float)>(Ease::easeOutElastic);
            }else if(functionType == EaseType::ELASTIC_IN_OUT){
                return Function<float(float)>(Ease::easeInOutElastic);
            }else if(functionType == EaseType::BACK_IN){
                return Function<float(float)>(Ease::easeInBack);
            }else if(functionType == EaseType::BACK_OUT){
                return Function<float(float)>(Ease::easeOutBack);
            }else if(functionType == EaseType::BACK_IN_OUT){
                return Function<float(float)>(Ease::easeInOutBack);
            }else if(functionType == EaseType::BOUNCE_IN){
                return Function<float(float)>(Ease::easeInBounce);
            }else if(functionType == EaseType::BOUNCE_OUT){
                return Function<float(float)>(Ease::easeOutBounce);
            }else if(functionType == EaseType::BOUNCE_IN_OUT){
                return Function<float(float)>(Ease::easeInOutBounce);
            }

            return Function<float(float)>(Ease::linear);
        }
    };
}


#endif //EASE_H
