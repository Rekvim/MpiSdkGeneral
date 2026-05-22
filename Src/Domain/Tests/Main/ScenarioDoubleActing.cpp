#include "ScenarioDoubleActing.h"
#include "RunnerDoubleActing.h"

namespace Domain::Tests::Main {

ScenarioDoubleActing::ScenarioDoubleActing(Tests::Context context,
                                           const Params& params,
                                           QObject* parent)
    : Scenario(context, params, parent)
{
}

std::unique_ptr<BaseRunner> ScenarioDoubleActing::createRunner()
{
    const bool normalOpen = m_context.config.safePosition == SafePosition::NormallyOpen;

    return std::make_unique<RunnerDoubleActing>(
        m_context.device,
        normalOpen,
        m_params,
        this
        );
}

void ScenarioDoubleActing::afterRunnerCreated(BaseRunner& baseRunner)
{
    Scenario::afterRunnerCreated(baseRunner);

    auto& runner = static_cast<RunnerDoubleActing&>(baseRunner);

    connect(&runner, &RunnerDoubleActing::waitingForManualResume,
            this, &ScenarioDoubleActing::waitingForManualResume,
            Qt::QueuedConnection);
}

}
