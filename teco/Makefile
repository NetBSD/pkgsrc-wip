# $NetBSD: Makefile,v 1.2 2012/10/07 17:17:28 asau Exp $

DISTNAME=	tecoclinux0398
PKGNAME=	teco-0398
CATEGORIES=	editors
MASTER_SITES=	http://almy.us/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://almy.us/teco.html
COMMENT=	Powerful and compact editor with nongrafical user interface

MAKE_FILE=	makefile
WRKSRC=		${WRKDIR}/tecoc${PKGVERSION}
BUILD_DIRS=	src
BUILD_TARGET=	#

DOCSFILES=	src/readme.1st src/readme.lnx src/changes.txt src/aaout.txt \
		src/problems.txt src/video.txt doc/teco.doc doc/wchart.txt

INSTALLATION_DIRS+=	bin share/teco share/doc/teco

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tecoc ${DESTDIR}${PREFIX}/bin/
	for f in ${WRKSRC}/lib/*; do \
	${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/teco/; \
	done
.for file in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/teco/
.endfor

.include "../../mk/bsd.pkg.mk"
