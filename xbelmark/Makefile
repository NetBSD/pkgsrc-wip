# $NetBSD: Makefile,v 1.11 2014/01/25 10:45:28 thomasklausner Exp $

DISTNAME=		xbelmark.py
PKGNAME=		xbelmark-20040924
CATEGORIES=		textproc www
MASTER_SITES=		http://0pointer.de/lennart/projects/xbelmark/
EXTRACT_SUFX=		# nothing to extract

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://0pointer.de/lennart/projects/xbelmark/
COMMENT=		XBEL XML bookmarks to readable HTML converter
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}
NO_BUILD=		YES

REPLACE_PYTHON=	xbelmark.py

do-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xbelmark
	${INSTALL_DATA} ${FILESDIR}/README ${DESTDIR}${PREFIX}/share/doc/xbelmark/
	${INSTALL_SCRIPT} ${WRKSRC}/xbelmark.py ${DESTDIR}${PREFIX}/bin/xbelmark.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
