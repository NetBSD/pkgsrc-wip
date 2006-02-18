# $NetBSD: Makefile,v 1.10 2006/02/18 23:15:19 tnn2 Exp $
#

DISTNAME=	valknut
CATEGORIES=	net x11

MAINTAINER=	tnn+nbsd@nygren.pp.se
HOMEPAGE=	http://dcgui.berlios.de/
COMMENT=	Direct Connect client using the QT toolkit (cvs version)

BUILD_DEPENDS+=         qt3-tools-3.*:../../x11/qt3-tools

.include "Makefile.common"

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../wip/dclib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
