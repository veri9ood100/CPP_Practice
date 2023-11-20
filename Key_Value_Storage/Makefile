# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable name
TARGET1 = kv_linked_list
TARGET2 = kv_vector_storage
TARGET3 = kv_array_storage

# Define the directory for the source files
SRCDIR1 = linked_list
SRCDIR2 = vector
SRCDIR3 = array

# Define object files
OBJ1 = $(SRCDIR1)/linked_list.o $(SRCDIR1)/kv_list.o
OBJ2 = $(SRCDIR2)/vector.o $(SRCDIR2)/kv_vector.o
OBJ3 = $(SRCDIR3)/array.o $(SRCDIR3)/kv_array.o

# Default target
all: $(TARGET1) $(TARGET2) $(TARGET3)

# If user wants to build particular file
ll: $(TARGET1)
vt: $(TARGET2)
arr:$(TARGET3)

# Rule to link the target executable
$(TARGET1): $(OBJ1)
	$(CXX) $(CXXFLAGS) -o $(TARGET1) $(OBJ1)
$(TARGET2): $(OBJ2)
	$(CXX) $(CXXFLAGS) -o $(TARGET2) $(OBJ2)
$(TARGET3): $(OBJ3)
	$(CXX) $(CXXFLAGS) -o $(TARGET3) $(OBJ3)


# Rule to compile the linked_list.o and vector.o file
$(SRCDIR1)/linked_list.o: $(SRCDIR1)/linked_list.cpp $(SRCDIR1)/kv_list.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR1)/linked_list.cpp -o $(SRCDIR1)/linked_list.o
$(SRCDIR2)/vector.o: $(SRCDIR2)/vector.cpp $(SRCDIR2)/kv_vector.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR2)/vector.cpp -o $(SRCDIR2)/vector.o
$(SRCDIR3)/vector.o: $(SRCDIR3)/vector.cpp $(SRCDIR3)/kv_vector.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR3)/vector.cpp -o $(SRCDIR3)/vector.o

# Rule to compile the kv_list.o and kv_vector.o file
$(SRCDIR1)/kv_list.o: $(SRCDIR1)/kv_list.cpp $(SRCDIR1)/kv_list.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR1)/kv_list.cpp -o $(SRCDIR1)/kv_list.o
$(SRCDIR2)/kv_vector.o: $(SRCDIR2)/kv_vector.cpp $(SRCDIR2)/kv_vector.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR2)/kv_vector.cpp -o $(SRCDIR2)/kv_vector.o
$(SRCDIR3)/kv_vector.o: $(SRCDIR3)/kv_vector.cpp $(SRCDIR3)/kv_vector.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR3)/kv_vector.cpp -o $(SRCDIR3)/kv_vector.o

# Target to clean the build files
clean:
	rm -f $(SRCDIR1)/*.o $(TARGET1) $(SRCDIR2)/*.o $(TARGET2) $(SRCDIR3)/*.o $(TARGET3)

clean_ll:
	rm -f $(SRCDIR1)/*.o $(TARGET1)

clean_vt:
	rm -f $(SRCDIR2)/*.o $(TARGET2)

clean_arr:
	rm -f $(SRCDIR3)/*.o $(TARGET3)
