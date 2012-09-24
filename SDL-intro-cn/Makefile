# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:28 asau Exp $
#

DISTNAME=		SDL-1.0-chinese-intro
PKGNAME=		SDL-intro-cn-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=	http://www.libsdl.org/archives/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.libsdl.org/docs.php
COMMENT=		Simple DirectMedia Layer introduction (Chinese)

WRKSRC=			${WRKDIR}/intro.cn
DEST=			${PREFIX}/share/doc/SDL-intro/cn

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
