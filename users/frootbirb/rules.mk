SRC += frootbirb.c

ifndef TAP_DANCE_ENABLE
  TAP_DANCE_ENABLE = yes
endif

COMBO_ENABLE = yes
NKRO_ENABLE = yes

# Filesize reduction
EXTRAFLAGS += -flto
MOUSEKEY_ENABLE = no
