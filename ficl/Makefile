# $NetBSD: Makefile,v 1.2 2008/02/21 18:28:21 asau Exp $

DISTNAME=	ficl4.0.31
PKGNAME=	ficl-4.0.31
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ficl/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://ficl.sourceforge.net/
COMMENT=	Forth Inspired Command Language

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
MAKE_FILE=	Makefile.linux
BUILD_TARGET=	ficl

MAJOR=		4
MINOR=		0.31
BUILD_TARGET+=	libficl.so.${MAJOR}.${MINOR}

FICL_DIRS+=	contrib contrib/xclasses
FICL_DIRS+=	doc doc/articles doc/graphics doc/source softcore test

INSTALLATION_DIRS=	bin share/ficl include include/ficlplatform lib
INSTALLATION_DIRS+=	${FICL_DIRS:C/^/share\/ficl\//}
do-install:
# install interpreter:
	${INSTALL_PROGRAM} ${WRKSRC}/ficl ${DESTDIR}${PREFIX}/bin
# install libraries:
	${INSTALL_LIB} ${WRKSRC}/libficl.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libficl.so.${MAJOR}.${MINOR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libficl.so ${DESTDIR}${PREFIX}/lib
# install header files:
	cd ${WRKSRC}; \
	for f in ficl.h ficlcompatibility.h ficllocal.h ficltokens.h; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/include; done
	cd ${WRKSRC}/ficlplatform; \
	for f in alpha.h ansi.h unix.h win32.h; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/include/ficlplatform; done
# install documentation and supplementary files:
	cd ${WRKSRC}; \
	for d in ${FICL_DIRS}; do \
		for f in $$d/*; do \
			if [ -f "$$f" ]; then \
				${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/ficl/$$d; \
	fi; done; done

.include "../../mk/bsd.pkg.mk"
