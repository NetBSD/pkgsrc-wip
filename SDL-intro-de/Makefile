# $NetBSD: Makefile,v 1.2 2011/11/30 12:52:59 noud4 Exp $
#

DISTNAME=		SDL-1.0-german-intro
PKGNAME=		SDL-intro-de-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=	http://www.libsdl.org/archives/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.libsdl.org/docs.php
COMMENT=		Simple DirectMedia Layer introduction (German)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/intro.de
DEST=			${PREFIX}/share/doc/SDL-intro/de

NO_CONFIGURE=	YES
NO_BUILD=		YES

# Remove links
post-patch:
	${RM} ${WRKSRC}/index.html

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DEST}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DESTDIR}${DEST}
	${LN} -s ${DEST}/toc.html ${DESTDIR}${DEST}/index.html

.include "../../mk/bsd.pkg.mk"
