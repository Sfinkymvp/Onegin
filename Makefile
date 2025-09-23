FLAGS = -D_DEBUG -ggdb3 -std=c++17 -O0 \
  -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat \
  -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts \
  -Wconditionally-supported -Wconversion -Wctor-dtor-privacy \
  -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security \
  -Wformat-signedness -Wformat=2 -Winline -Wlogical-op \
  -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked \
  -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow \
  -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 \
  -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types \
  -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef \
  -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros \
  -Wno-literal-suffix -Wno-missing-field-initializers \
  -Wno-narrowing -Wno-old-style-cast -Wno-varargs \
  -fcheck-new -fsized-deallocation -fstack-protector \
  -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer \
  -Wlarger-than=16384 -Wstack-usage=8192 -pie -fPIE -Werror=vla \
  -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr


OBJDIR = obj


$(OBJDIR):
	@mkdir -p $(OBJDIR)


osort: $(OBJDIR)/main.o $(OBJDIR)/input.o $(OBJDIR)/output.o $(OBJDIR)/sort.o $(OBJDIR)/args.o
	@g++ $(OBJDIR)/main.o $(OBJDIR)/input.o $(OBJDIR)/output.o $(OBJDIR)/sort.o \
	$(OBJDIR)/args.o $(FLAGS) -o osort


$(OBJDIR)/main.o: main.cpp | $(OBJDIR)
	@g++ -c main.cpp $(FLAGS) -o $(OBJDIR)/main.o


$(OBJDIR)/input.o: input.cpp | $(OBJDIR)
	@g++ -c input.cpp $(FLAGS) -o $(OBJDIR)/input.o


$(OBJDIR)/output.o: output.cpp | $(OBJDIR)
	@g++ -c output.cpp $(FLAGS) -o $(OBJDIR)/output.o


$(OBJDIR)/sort.o: sort.cpp | $(OBJDIR)
	@g++ -c sort.cpp $(FLAGS) -o $(OBJDIR)/sort.o


$(OBJDIR)/args.o: args.cpp | $(OBJDIR)
	@g++ -c args.cpp $(FLAGS) -o $(OBJDIR)/args.o
