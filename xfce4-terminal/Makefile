# $NetBSD: Makefile,v 1.2 2006/07/18 11:30:48 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.5.4beta2

DISTNAME=	Terminal-${XFCE4_VERSION}
PKGNAME=	xfce4-terminal-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce terminal emulator

.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
