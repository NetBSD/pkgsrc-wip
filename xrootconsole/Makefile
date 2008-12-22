# $NetBSD: Makefile,v 1.3 2008/12/22 03:02:22 gregschenzel Exp $

DISTNAME=	xrootconsole-0.6
PKGREVISION=	1
CATEGORIES=	x11

MAINTAINER=	inittab@unixdev.net
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=xrootconsole/}

HOMEPAGE=       http://xrootconsole.sourceforge.net/
COMMENT=        Windowless XConsole

USE_TOOLS+=             gmake

INSTALLATION_DIRS=      bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
