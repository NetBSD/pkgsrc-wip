# $NetBSD: Makefile,v 1.2 2006/07/18 11:30:48 marttikuparinen Exp $

#BROKEN=		Hangs during installation

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.6

DISTNAME=	mousepad-${XFCE4_VERSION}
PKGNAME=	xfce4-mousepad-${XFCE4_VERSION}
CATEGORIES=	editors
COMMENT=	Xfce text editor

.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
