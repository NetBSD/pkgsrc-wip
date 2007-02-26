# $NetBSD: Makefile,v 1.2 2007/02/26 08:10:52 netcap Exp $

TR_VERSION=	1.0
DISTNAME=	trayer-${TR_VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/fvwm-crystal/

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://fvwm-crystal.org/
COMMENT=	Standalone tray app

USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"

do-install:
	cp ${WRKSRC}/trayer ${PREFIX}/bin/

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
