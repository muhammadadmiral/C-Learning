# ============================================================
#  010 — Makefile: Automasi Build Multi-file Project
# ============================================================
#  Cara pakai:
#    make            → Build program
#    make clean      → Hapus file hasil compile
#    make debug      → Build dengan debug mode (-DDEBUG)
#    make run        → Build dan langsung jalankan
# ============================================================

# Compiler dan flags
CC      = gcc
CFLAGS  = -std=c17 -Wall -Wextra -Wpedantic
TARGET  = program

# Source files dan object files
SRCS    = main.c mathlib.c strutils.c
OBJS    = $(SRCS:.c=.o)

# ============================================================
# TARGETS
# ============================================================

# Target utama: link semua object files jadi executable
# $@ = nama target (program)
# $^ = semua dependencies (main.o mathlib.o strutils.o)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule: compile setiap .c jadi .o
# $< = dependency pertama (file .c)
# $@ = target (file .o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ============================================================
# DEPENDENCY RULES
# ============================================================
# Kalau header berubah, file yang include header itu harus di-recompile
main.o: main.c mathlib.h strutils.h
mathlib.o: mathlib.c mathlib.h
strutils.o: strutils.c strutils.h

# ============================================================
# PHONY TARGETS (bukan file, tapi perintah)
# ============================================================

.PHONY: clean debug run

# Hapus semua file hasil compile
clean:
	rm -f $(OBJS) $(TARGET)

# Build dengan debug mode
debug: CFLAGS += -DDEBUG -g
debug: clean $(TARGET)

# Build dan langsung jalankan
run: $(TARGET)
	./$(TARGET)
