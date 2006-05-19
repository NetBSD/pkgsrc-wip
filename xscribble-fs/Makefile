# $NetBSD: Makefile,v 1.2 2006/05/19 16:51:41 ykomatsu Exp $

DISTNAME=	xscribblefs
PKGNAME=	xscribble-fs-20001213
CATEGORIES=	x11
MASTER_SITES=	http://linuxslate.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxslate.com/software.html
COMMENT=	Handwriting recognition (like graffiti)

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

post-configure:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xscribble
	${INSTALL_DATA} ${WRKSRC}/classifiers/*.cl ${PREFIX}/share/examples/xscribble

.include "../../mk/bsd.pkg.mk"
