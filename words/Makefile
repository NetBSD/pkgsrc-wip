# $NetBSD: Makefile,v 1.2 2003/08/29 10:31:26 thomasklausner Exp $

DISTNAME=		linux.words.2
PKGNAME=		words-2
WRKSRC=			${WRKDIR}/usr/dict
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=libs/}

MAINTAINER=		tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=		English word list

NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/linux.words ${PREFIX}/share/dict/words
	${LN} -fs ${PREFIX}/share/dict/words ${PREFIX}/share/dict/linux.words
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/words
	${INSTALL_DATA} ${WRKSRC}/README.linux.words ${PREFIX}/share/doc/words/
	${INSTALL_DATA} ${WRKSRC}/README2.linux.words ${PREFIX}/share/doc/words/

.include "../../mk/bsd.pkg.mk"
