# $NetBSD: Makefile,v 1.6 2007/01/24 06:17:16 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	1.9.2

DISTNAME=	xfce4-quicklauncher-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-quicklauncher-plugin/
COMMENT=	Xfce quicklaunch plugin

USE_TOOLS+=	intltool

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
