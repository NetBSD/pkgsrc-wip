# $NetBSD: Makefile,v 1.5 2012/10/07 20:11:10 asau Exp $

DISTNAME=	xrootconsole-0.6
PKGREVISION=	2
CATEGORIES=	x11

MAINTAINER=	inittab@unixdev.net
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=xrootconsole/}

HOMEPAGE=       http://xrootconsole.sourceforge.net/
COMMENT=        Windowless XConsole

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+=             gmake

INSTALLATION_DIRS=      bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
