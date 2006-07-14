# $NetBSD: Makefile,v 1.1.1.1 2006/07/14 10:43:16 thomasklausner Exp $

BROKEN=		Must fix the p5 dependencies

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.1.8beta2

DISTNAME=	exo-${XFCE4_VERSION}
PKGNAME=	xfce4-exo-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce extension library

.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../wip/libxfce4mcs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
