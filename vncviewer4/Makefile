# $NetBSD: Makefile,v 1.1.1.1 2005/09/28 20:58:28 riz Exp $

DISTNAME=       	vnc-4_1_1-unixsrc
PKGNAME=		vncviewer-4.1.1
CATEGORIES=		net x11
MASTER_SITES=   	http://www.tastylime.net/mirror/realvnc/

MAINTAINER=	 	riz@NetBSD.org
HOMEPAGE=		http://www.realvnc.com/
COMMENT=		Viewer for remote X and Win32 VNC servers

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-installed-zlib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man \
		${PREFIX}/man/man1/vncviewer.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
