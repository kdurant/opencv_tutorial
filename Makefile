CC = g++
TARGET = main.exe
INC_DIRS += -IC:\Lib\opencv\install\include
INC_DIRS += -IC:\Lib\opencv\install\include\opencv2
LIB_PATH += -LC:\Lib\opencv\install\x64\mingw\lib
LIBS += -lopencv_calib3d453 -lopencv_core453 -lopencv_dnn453 -lopencv_features2d453 -lopencv_flann453 -lopencv_gapi453 -lopencv_highgui453 -lopencv_imgcodecs453 -lopencv_imgproc453 -lopencv_ml453 -lopencv_objdetect453 -lopencv_photo453 -lopencv_stitching453 -lopencv_video453 -lopencv_videoio453
SYMBOLS = 


SRC_FILES = main.cpp


all: default

default:
	@$(CC) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(TARGET) $(LIB_PATH) $(LIBS)
	@./$(TARGET)

clean:
	$(CLEANUP)
