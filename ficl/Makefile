# $NetBSD: Makefile,v 1.1.1.1 2008/02/05 19:47:02 asau Exp $

DISTNAME=	ficl4.0.31
PKGNAME=	ficl-4.0.31
PKGREVISION=	#
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ficl/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://ficl.sourceforge.net/
COMMENT=	Forth Inspired Command Language

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
MAKE_FILE=	Makefile.linux
BUILD_TARGET=	ficl

FICL_DIRS+=	contrib contrib/xclasses
FICL_DIRS+=	doc doc/articles doc/graphics doc/source softcore test

INSTALLATION_DIRS=	bin share/ficl
INSTALLATION_DIRS+=	${FICL_DIRS:C/^/share\/ficl\//}
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ficl ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}; \
	for d in ${FICL_DIRS}; do \
		for f in $$d/*; do \
			if [ -f "$$f" ]; then \
				${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/ficl/$$d; \
	fi; done; done

.include "../../mk/bsd.pkg.mk"
