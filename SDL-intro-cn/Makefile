# $NetBSD: Makefile,v 1.1 2005/05/31 09:30:42 ianzag Exp $
#

DISTNAME=		SDL-1.0-chinese-intro
PKGNAME=		SDL-intro-cn-1.0
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
	${INSTALL_DATA_DIR} ${DEST}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DEST}
	${LN} -s ${DEST}/toc.html ${DEST}/index.html

.include "../../mk/bsd.pkg.mk"
