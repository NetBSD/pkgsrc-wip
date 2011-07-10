# $NetBSD: Makefile,v 1.10 2011/07/10 19:00:44 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

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
