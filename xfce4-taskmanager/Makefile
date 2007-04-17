# $NetBSD: Makefile,v 1.7 2007/04/17 14:02:48 marttikuparinen Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.2

DISTNAME=	xfce4-taskmanager-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-taskmanager/
COMMENT=	Xfce task manager

USE_TOOLS+=	intltool

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
