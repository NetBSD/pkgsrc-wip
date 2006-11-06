# $NetBSD: Makefile,v 1.7 2006/11/06 11:00:26 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.10

DISTNAME=	mousepad-${XFCE4_VERSION}
PKGNAME=	xfce4-mousepad-${XFCE4_VERSION}
CATEGORIES=	editors
COMMENT=	Xfce text editor

USE_TOOLS+=	intltool

.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
