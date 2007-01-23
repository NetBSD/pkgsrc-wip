# $NetBSD: Makefile,v 1.2 2007/01/23 14:05:28 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.3

DISTNAME=	xfce4-xkb-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-xkb-plugin/
EXTRACT_SUFX=	.tar.bz2
COMMENT=	Xfce Keyboard plugin

USE_TOOLS+=	intltool

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
