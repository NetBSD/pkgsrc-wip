# $NetBSD: Makefile,v 1.1 2005/05/31 09:39:50 ianzag Exp $
#

DISTNAME=		SDL-1.0-italian-intro
PKGNAME=		SDL-intro-it-1.0
CATEGORIES=		devel
MASTER_SITES=	http://www.libsdl.org/archives/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.libsdl.org/docs.php
COMMENT=		Simple DirectMedia Layer introduction (Italian)

WRKSRC=			${WRKDIR}/intro.it
DEST=			${PREFIX}/share/doc/SDL-intro/it

NO_CONFIGURE=	YES
NO_BUILD=		YES

# Remove links
post-patch:
	${RM} ${WRKSRC}/index.html

do-install:
	${INSTALL_DATA_DIR} ${DEST}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DEST}
	${LN} -s ${DEST}/toc.html ${DEST}/index.html

.include "../../mk/bsd.pkg.mk"
