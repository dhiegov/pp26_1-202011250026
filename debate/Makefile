CXX := g++
TARGET := debate
SRCS := main.cpp Microfone.cpp Candidato.cpp GerenciadorDebate.cpp Logger.cpp Fachada.cpp Cronometro.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

.PHONY: all run clean

-include $(DEPS)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.d *.o $(TARGET)

