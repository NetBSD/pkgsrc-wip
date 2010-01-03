# $NetBSD: Makefile,v 1.5 2010/01/03 15:14:29 pallegra Exp $
#

.include "../../wip/gl/Makefile.common"

PKGNAME=	${COMPONENT}-${MESA_PKGVERSION}
CATEGORIES=	graphics
EXTRACT_SUFX=	.tar.bz2

COMPONENT=	glx-utils

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	OpenGL glxgears and glxinfo
#LICENSE=	# TODO: (see mk/license.mk)

NO_CONFIGURE=	yes

do-build:
	cd ${WRKSRC}/progs/xdemos && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		glxgears.c ${LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext \
		-o glxgears && \
	${SETENV} ${MAKE_ENV} ${CC} -I../../include ${CFLAGS} \
		glxinfo.c ${LDFLAGS} \
		-L../../lib -lGLU -lGL -lm -lXext -o glxinfo

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxgears \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/glxinfo \
		${DESTDIR}${PREFIX}/bin/

.include "../../wip/glu/buildlink3.mk"
.include "../../wip/gl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
