# $NetBSD: Makefile,v 1.3 2006/09/07 08:27:47 marttikuparinen Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.9.1

DISTNAME=	xfce4-quicklauncher-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
EXTRACT_SUFX=	.tar.bz2
COMMENT=	Xfce quicklaunch plugin

USE_TOOLS+=	intltool

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
