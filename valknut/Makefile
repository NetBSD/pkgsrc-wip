# $NetBSD: Makefile,v 1.7 2005/05/24 10:31:48 rillig Exp $
#

DISTNAME=	valknut-0.3.7
CATEGORIES=	net x11
MASTER_SITES=	http://download.berlios.de/dcgui/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://dcgui.berlios.de/
COMMENT=	Direct Connect client using the QT toolkit

DEPENDS+=               dclib>=0.3.7:../../wip/dclib
BUILD_DEPENDS+=         qt3-tools-3.*:../../x11/qt3-tools

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../wip/dclib/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
