# Makefile for File-renamer
#
# If you installed boost using the included ./install--boost.sh
# script, change HEADERS to "-I ./" and change BOOST_LIB_DIR to 
# "-L ./lib"

CC		:=	g++
HEADERS		:=	-I /usr/local
SRC		:=	bank.cpp inventory.cpp player.cpp board_space.cpp property.cpp main.cpp utility.cpp
OBJ		:=	${SRC:.cpp=.o}
BOOST_LIB_DIR	:=	-L /usr/local/lib/boost_static
BOOST_LIB	:=	-lboost_system -lboost_program_options
LIBS		:=	${BOOST_LIB_DIR} ${BOOST_LIB}
LOG_FILE	:=	>> build.log
CFLAGS		:=	-W -Wall -Werror -pedantic -pthread ${HEADERS} -g
NAME		:=	main

main: ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${LIBS} ${LOG_FILE}

run: main
	${NAME}

# generate dependancy files at the same time as object compilation
%.o : %.cpp
	${CC} ${CFLAGS} -MD -o $@ -c ${LOGFILE} $< 
	@cp $*.d $*.P; \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	 	  -e '/^$$/ d' -e 's/$$/ :/' < $*.P >> $*.d; \
	  rm -f $*.P
clean:
	rm -f *.o *~ core *.log *.save
exclean: clean
	rm -f ${NAME}
