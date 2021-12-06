MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
TAP_DANCE_ENABLE = yes

EXTRAFLAGS += -flto

SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        ./lib/timelogger.c \
		./lib/typecount_render.c \
        #./lib/mode_icon_reader.c \
        #./lib/host_led_state_reader.c \
