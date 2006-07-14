# $NetBSD: Makefile,v 1.1.1.1 2006/07/14 10:43:15 thomasklausner Exp $

BROKEN=		Must fix xfce4-exo first

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.2beta2

DISTNAME=	Thunar-${XFCE4_VERSION}
PKGNAME=	xfce4-thunar-${XFCE4_VERSION}
CATEGORIES=	sysutils
COMMENT=	Xfce file manager

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
