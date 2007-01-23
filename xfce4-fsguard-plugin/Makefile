# $NetBSD: Makefile,v 1.4 2007/01/23 14:03:42 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.0

DISTNAME=	xfce4-fsguard-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-fsguard-plugin/
EXTRACT_SUFX=	.tar.bz2
COMMENT=	Xfce disk space plugin

USE_TOOLS+=	intltool

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
