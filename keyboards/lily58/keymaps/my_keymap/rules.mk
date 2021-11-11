MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
OLED_ENABLE= yes

SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        ./lib/timelogger.c \
		./lib/typecount_render.c \
        #./lib/mode_icon_reader.c \
        #./lib/host_led_state_reader.c \
