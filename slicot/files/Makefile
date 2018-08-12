SRCS!= echo *.f

PREFIX?=		/usr/pkg
LIBDIR?=		${PREFIX}/lib
SHLIBINSTALLDIR?=	${PREFIX}/lib

LIB=		slicot
LDADD+=		-llapack -lblas
LDFLAGS+=	-L${LIBDIR} -Wl,-R,${LIBDIR}

MKUNPRIVED=	yes

.include <bsd.lib.mk>
