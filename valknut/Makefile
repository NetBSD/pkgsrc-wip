# $NetBSD: Makefile,v 1.9 2006/02/15 17:47:47 tnn2 Exp $
#

DISTNAME=	valknut
CATEGORIES=	net x11

MAINTAINER=	tnn@nygren.pp.se
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
