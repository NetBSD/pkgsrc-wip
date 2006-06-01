#! /bin/sh
#minimalistic pkgsrc-friendly build script to avoid scons dependency
CXXFLAGS="${CPPFLAGS} ${CXXFLAGS} ${PTHREAD_CFLAGS} -c -g -D_DEBUG -D_GNU_SOURCE -DENABLE_BINRELOC -I . -D_FILE_OFFSET_BITS=64 -D_PREFIX=\"${PREFIX}\" -D_DATADIR=\"${PREFIX}/share\" `pkg-config --cflags libglade-2.0 gthread-2.0`"
LDFLAGS="${LDFLAGS} ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS} `pkg-config --libs libglade-2.0 gthread-2.0` -lz -lbz2"
FILES="`echo */*.cpp */*.cc`"
for FILE in ${FILES}
do
OBJ="${FILE}.o"
OBJS="${OBJS} $OBJ"
cmd="${CXX} ${CXXFLAGS} -o ${FILE}.o ${FILE}"
echo $cmd; test -e $OBJ || $cmd || exit 1
done
FILES="`echo */*.c`"
for FILE in ${FILES}
do
OBJ="${FILE}.o"
OBJS="${OBJS} $OBJ"
cmd="${CC} ${CXXFLAGS} -o ${FILE}.o ${FILE}"
echo $cmd; test -e $OBJ || $cmd || exit 1
done
cmd="${CXX} -o ldcpp ${OBJS} ${LDFLAGS}"
echo $cmd; $cmd || exit 1
