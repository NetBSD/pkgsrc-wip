# $NetBSD: Makefile,v 1.3 2008/08/02 10:20:05 milosn Exp $

TR_VERSION=	1.0
DISTNAME=	trayer-${TR_VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/fvwm-crystal/
PKGREVISION=    1

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://fvwm-crystal.org/
COMMENT=	Standalone tray app

USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"

do-install:
	cp ${WRKSRC}/trayer ${PREFIX}/bin/

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
