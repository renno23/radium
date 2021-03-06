#ifdef MEMORY_DEBUG
extern LANGSPEC void PLAYER_memory_debug_wake_up(void);
#else
#define PLAYER_memory_debug_wake_up()
#endif

extern LANGSPEC bool MIXER_start(void);

extern LANGSPEC bool MIXER_is_saving(void);
extern LANGSPEC void MIXER_start_saving_soundfile(void);
extern LANGSPEC void MIXER_request_stop_saving_soundfile(void);

extern LANGSPEC void OS_InitAudioTiming(void);
extern LANGSPEC STime MIXER_get_block_delta_time(STime time);
extern LANGSPEC int64_t MIXER_get_time(void);
extern LANGSPEC STime MIXER_get_accurate_radium_time(void);
extern LANGSPEC void MIXER_RT_set_bus_descendand_type_for_all_plugins(void);

#ifdef __cplusplus

struct SoundProducer;

extern void MIXER_add_SoundProducer(SoundProducer *sound_producer);

extern void MIXER_remove_SoundProducer(SoundProducer *sound_producer);

#include "SoundProducer_proc.h"
extern DoublyLinkedList *MIXER_get_all_SoundProducers(void);

#endif // __cplusplus

extern LANGSPEC struct Patch **RT_MIXER_get_all_click_patches(int *num_click_patches);

extern LANGSPEC float MIXER_get_sample_rate(void);

extern LANGSPEC int MIXER_get_buffer_size(void);
