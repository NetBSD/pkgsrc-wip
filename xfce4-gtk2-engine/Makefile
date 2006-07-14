# $NetBSD: Makefile,v 1.1.1.1 2006/07/14 10:43:16 thomasklausner Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	2.3.90.2

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce GTK2 themes

USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
