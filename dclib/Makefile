# $NetBSD: Makefile,v 1.11 2006/02/15 17:18:08 tnn2 Exp $
#

DISTNAME=	dclib
CATEGORIES=	net

MAINTAINER=	tnn+nbsd@nygren.pp.se
HOMEPAGE=	http://dcgui.berlios.de/
COMMENT=	Direct Connect P2P library (cvs version)

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	dclib.pc.in

.include "../../wip/valknut/Makefile.common"

.include "../../wip/libootool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
