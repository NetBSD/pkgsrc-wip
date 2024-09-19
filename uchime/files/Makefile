
BIN =	uchime
OBJS =	addtargets2.o alignchime.o alignchimel.o alnparams.o alpha.o alpha2.o fractid.o getparents.o globalalign2.o make3way.o mx.o myutils.o path.o searchchime.o seqdb.o setnucmx.o sfasta.o tracebackbit.o uchime_main.o usort.o viterbifast.o writechhit.o

CXXFLAGS ?=	-O3 -msse2 -mfpmath=sse
CXXFLAGS +=	-D_FILE_OFFSET_BITS=64 -DNDEBUG=1 -DUCHIMES=1

MKDIR ?=	mkdir
INSTALL ?=	install
PREFIX ?=	/usr/local
DESTDIR ?=	.
STRIP ?=	strip

clean:
	rm -f *.o mk.stdout mk.stderr tmp.stderr

all: ${BIN}

${BIN}: ${OBJS}
	${CXX} -o ${BIN} ${OBJS} ${LDFLAGS}

%.o: %.c:
	${CXX} -c ${CXXFLAGS} $<

install:
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	${INSTALL} -c ${BIN} ${DESTDIR}${PREFIX}/bin

install-strip: install
	${STRIP} ${DESTDIR}${PREFIX}/bin/${BIN}
