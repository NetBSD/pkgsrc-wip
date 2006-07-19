# $NetBSD: Makefile,v 1.3 2006/07/19 07:29:00 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.5.4beta2

DISTNAME=	Terminal-${XFCE4_VERSION}
PKGNAME=	xfce4-terminal-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce terminal emulator

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
