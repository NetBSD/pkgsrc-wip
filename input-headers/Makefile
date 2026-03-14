# $NetBSD$

.include "../../wip/libopeninput/Makefile.common"

PKGNAME=	input-headers-${VERSION}
COMMENT=	Input headers from libopeninput

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	include/linux

do-configure:

do-build:

do-install:
	${RUN} cd ${WRKSRC}/include/linux && \
		${FIND} . -type f -name "*.h" -print | pax -rw -pmp ${DESTDIR}${PREFIX}/include/linux

.include "../../mk/bsd.pkg.mk"
