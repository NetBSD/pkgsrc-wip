# $NetBSD: Makefile,v 1.3 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	opencascade-7.0.0
CATEGORIES=	cad
# Official webpage requires login
MASTER_SITES=	https://sources.archlinux.org/other/community/opencascade/
EXTRACT_SUFX=	.tgz

MAINTAINER=	silasdb@gmail.com
HOMEPAGE=	http://www.opencascade.org/
COMMENT=	Software development platform for 3D CAD CAM CAE

LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes

USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM.NetBSD+=   rm:-ldl

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
