#ifndef MIXER_PREVIEWDECK_H
#define MIXER_PREVIEWDECK_H

#include "mixer/basetrackplayer.h"

class PreviewDeck : public BaseTrackPlayerImpl {
    Q_OBJECT
  public:
    PreviewDeck(QObject* pParent,
            UserSettingsPointer pConfig,
            EngineMaster* pMixingEngine,
            EffectsManager* pEffectsManager,
            VisualsManager* pVisualsManager,
            EngineChannel::ChannelOrientation defaultOrientation,
<<<<<<< HEAD
            const ChannelHandleAndGroup& handleGroup);
=======
            const QString& group);
>>>>>>> upstream/2.3
    ~PreviewDeck() override = default;
};

#endif /* MIXER_PREVIEWDECK_H */
