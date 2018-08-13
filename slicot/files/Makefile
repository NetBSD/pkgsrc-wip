SRCS!= echo *.f

PREFIX?=		/usr/pkg
LIBDIR?=		${PREFIX}/lib
SHLIBINSTALLDIR?=	${PREFIX}/lib
INSTPRIV=		-U

LIB=		slicot
LDADD+=		-llapack -lblas
LDFLAGS+=	-L${LIBDIR} -Wl,-R,${LIBDIR}

.include <bsd.lib.mk>

LIBCC:=			${FC}
