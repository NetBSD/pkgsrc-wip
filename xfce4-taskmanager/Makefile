# $NetBSD: Makefile,v 1.3 2005/11/06 16:33:43 marttikuparinen Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.1

DISTNAME=	xfce4-taskmanager-${XFCE4_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 task manager

PKGREVISION=	1

.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
