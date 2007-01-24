# $NetBSD: Makefile,v 1.1.1.1 2007/01/24 08:26:50 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.6.0

DISTNAME=	xfce4-weather-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-weather-plugin/
COMMENT=	Xfce weather plugin

USE_TOOLS+=	intltool

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
