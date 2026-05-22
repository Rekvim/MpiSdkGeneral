#pragma once

#include "Scenario.h"

namespace Domain::Tests::Main {

class ScenarioDoubleActing : public Scenario
{
    Q_OBJECT

public:
    ScenarioDoubleActing(Tests::Context context,
                         const Params& params,
                         QObject* parent = nullptr);

protected:
    std::unique_ptr<BaseRunner> createRunner() override;
    void afterRunnerCreated(BaseRunner& runner) override;
};

}
