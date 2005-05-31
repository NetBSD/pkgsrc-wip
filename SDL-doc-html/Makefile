# $NetBSD: Makefile,v 1.1 2005/05/31 12:20:02 ianzag Exp $
#

DISTNAME=		sdldoc-html
PKGNAME=		SDL-doc-html-1.0
CATEGORIES=		devel
MASTER_SITES=	http://www.libsdl.org/archives/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.libsdl.org/docs.php
COMMENT=		Simple DirectMedia Layer documentation

WRKSRC=			${WRKDIR}/html
DEST=			${PREFIX}/share/doc/SDL-doc/html

NO_CONFIGURE=	YES
NO_BUILD=		YES

do-install:
	${INSTALL_DATA_DIR} ${DEST}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DEST}

.include "../../mk/bsd.pkg.mk"
