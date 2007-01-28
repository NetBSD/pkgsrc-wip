PROG=	mp3gain
SRCS=	mp3gain.c apetag.c gain_analysis.c rg_error.c \
	common.c dct64_i386.c \
	decode_i386.c interface.c \
	layer3.c tabinit.c
NOMAN=	# no man

LDADD=	-lm
DPADD=	${LIBM}

.PATH: ${.CURDIR}/mpglibDBL

.include <bsd.prog.mk>
