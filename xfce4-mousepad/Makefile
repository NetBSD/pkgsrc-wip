# $NetBSD: Makefile,v 1.6 2006/09/04 08:54:04 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.8

DISTNAME=	mousepad-${XFCE4_VERSION}
PKGNAME=	xfce4-mousepad-${XFCE4_VERSION}
CATEGORIES=	editors
COMMENT=	Xfce text editor

USE_TOOLS+=	intltool

.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
