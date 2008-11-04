# $NetBSD: Makefile,v 1.2 2008/11/04 23:54:08 gregschenzel Exp $

DISTNAME=	xrootconsole-0.6
PKGREVISION=	1
CATEGORIES=	x11

MAINTAINER=	inittab@unixdev.net
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=xrootconsole/}

HOMEPAGE=       http://xrootconsole.sourceforge.net/
COMMENT=        Windowless XConsole

USE_TOOLS+=             gmake

LIBS.SunOS+=            -lX11
INSTALLATION_DIRS=      bin ${PKGMANDIR}/man1

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
