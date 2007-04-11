# $NetBSD: Makefile,v 1.2 2007/04/11 14:48:50 hoka_adam Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.1

DISTNAME=	xfce4-xmms-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-xmms-plugin/
COMMENT=	Xfce XMMS plugin

USE_TOOLS+=	intltool

.include "options.mk"

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
