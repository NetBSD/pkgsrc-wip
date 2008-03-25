# $NetBSD: Makefile,v 1.3 2008/03/25 19:31:27 bsadewitz Exp $

DISTNAME=	MesaDemos-${MESA_VERSION}
PKGNAME=	glx-utils-${MESA_PKGVERSION}
PKGREVISION=	1
CATEGORIES=	x11 graphics
COMMENT=	OpenGL glxgears and glxinfo

.include "../../wip/Mesa/Makefile.common"

INSTALLATION_DIRS=	bin

.include "../../wip/glu/buildlink3.mk"
.include "../../wip/MesaLib/buildlink3.mk"

do-build:
	cd ${WRKSRC}/progs/xdemos && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		${PTHREAD_CFLAGS} glxgears.c ${LDFLAGS} ${PTHREAD_LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext ${PTHREAD_LIBS} \
		-o glxgears && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		${PTHREAD_CFLAGS} glxinfo.c ${LDFLAGS} ${PTHREAD_LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext ${PTHREAD_LIBS} -o glxinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxgears ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxinfo ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
