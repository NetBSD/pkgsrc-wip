# $NetBSD: Makefile,v 1.7 2006/08/19 20:09:04 cheusov Exp $

DISTNAME=	xxkb-1.10
#PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xxkb/} \
		http://pascal.tsu.ru/other/xxkb/

MAINTAINER=	cheusov@tut.by
# Unfortunately home page is currently written in Russian language
# only.  See http://pascal.tsu.ru/en/ for English translation updates.
HOMEPAGE=	http://pascal.tsu.ru/other/xxkb/
COMMENT=	XXKB - switches and indicates a current keyboard layout

USE_IMAKE=		yes
DOC_FILES=		LICENSE README.koi8
DOC_DIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOC_DIR}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOC_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
.include "../../mk/x11.buildlink3.mk"
