# $NetBSD: Makefile,v 1.1 2004/09/03 17:44:45 tnn2 Exp $
#

DISTNAME=	valknut-0.3.3
CATEGORIES=	net x11
MASTER_SITES=	http://download.berlios.de/dcgui/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://dcgui.berlios.de/
COMMENT=	Direct Connect client using the QT toolkit

DEPENDS+=               dclib>=0.3.3:../../wip/dclib
BUILD_DEPENDS+=         qt3-tools-3.*:../../x11/qt3-tools

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"
.include "../../wip/dclib/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
