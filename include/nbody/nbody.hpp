#pragma once

#include <vector>

namespace nbody {
    struct Body {
        double x{0.0};
        double y{0.0};

        double xvel{0.0};
        double yvel{0.0};

        double mass{1.0};
    };

}