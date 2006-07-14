# $NetBSD: Makefile,v 1.1.1.1 2006/07/14 10:43:15 thomasklausner Exp $

BROKEN=		Must fix xfce4-exo first

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.5.4beta2

DISTNAME=	Terminal-${XFCE4_VERSION}
PKGNAME=	xfce4-terminal-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce terminal emulator

.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
