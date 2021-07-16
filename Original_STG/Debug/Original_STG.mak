#-------------------------------------------------------
# BCC Developer 1.2.21
# Copyright (C) 2003 jun_miura@hi-ho.ne.jp
#-------------------------------------------------------
.autodepend
CC=bcc32
RC=brc32
CFLAG=-W  -3 -Od -w- -AT -pc -H- -k -b -v -y  -DDEBUG
OUTDIR=-nDebug
CINCS=
TARGET=Debug\Original_STG.exe
SRC1=C:\Users\ic201239\Documents\Cpp\Original_STG\STD_main.cpp
OBJ1=Debug\STD_main.obj

TARGET: $(TARGET)

$(TARGET): $(OBJ1)
    $(CC) $(CFLAG) -e$(TARGET) $(OBJ1)

$(OBJ1): $(SRC1)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC1)
