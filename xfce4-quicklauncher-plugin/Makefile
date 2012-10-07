# $NetBSD: Makefile,v 1.11 2012/10/07 20:11:09 asau Exp $

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	xfce4-quicklauncher-plugin-1.9.4
PKGREVISION=	7
CATEGORIES=	sysutils
COMMENT=	Xfce quicklaunch plugin

MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-quicklauncher-plugin/1.9/

#XFCE4_PROJECT=  	xfce4-panel
#XFCE4_BRANCH=		4.8

USE_LANGUAGES+=		c c++

.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
