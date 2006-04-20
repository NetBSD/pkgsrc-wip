# $NetBSD: Makefile,v 1.1 2006/04/20 10:47:01 cheusov Exp $
DISTNAME=	xxkb-1.10
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pascal.tsu.ru/other/xxkb/

MAINTAINER=	cheusov@tut.by

# Unfortunately home page is currently written in Russian language
# only.  See http://pascal.tsu.ru/en/ for English translation updates.
HOMEPAGE=	http://pascal.tsu.ru/other/xxkb/
COMMENT=	XXKB - switches and indicates a current keyboard layout

USE_IMAKE=	yes
DOC_FILES=	LICENSE README.koi8
DOC_DIR=	${PREFIX}/share/doc/xxkb

post-install:
	${INSTALL_DATA_DIR} ${DOC_DIR}; \
	for i in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${DOC_DIR}; \
	done; \
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man1; \
	${INSTALL_MAN} ${WRKSRC}/xxkb.man ${PREFIX}/${PKGMANDIR}/man1/xxkb.1

.include "../../mk/bsd.pkg.mk"
