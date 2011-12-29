CPPFLAGS=	-I../.. -I..			\
		-DHAMMER_TIME=1 		\
		-DLOGGING=1			\
		-DFEATURE_ENABLE_SSL 		\
		-DFEATURE_ENABLE_VOICEMAIL 	\
		-DFEATURE_ENABLE_PSTN 		\
		-DHAVE_SRTP			\
		-DHASHNAMESPACE=__gnu_cxx	\
		-DHASH_NAMESPACE=__gnu_cxx	\
    		-DPOSIX				\
		-DBSD				\
		-DDISABLE_DYNAMIC_CAST		\
    		-DHAVE_OPENSSL_SSL_H=1		\
    		-D_REENTRANT
CFLAGS=		-Wall -Werror -Wno-switch -fno-exceptions -fvisibility=hidden -gdwarf-2
CXXFLAGS=	-Wno-non-virtual-dtor -Wno-ctor-dtor-privacy -fno-rtti
LTCOMP=		libtool --mode=compile --silent
CXX=		${LTCOMP} c++

#SRCS=		$(wildcard *.cc)
SRCS=		$(shell find . \( -name "*.cc" -a \! -name "*_unittest.cc" -a \! -name "mac*" -a \! -name "win32*" \))
OBJS=		$(SRCS:.cc=.o)

all: $(OBJS)

.cc.o:
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c $< -o $@
