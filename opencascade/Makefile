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

#GNU_CONFIGURE_PREFIX=	${PREFIX}/opencascade

#GNU_CONFIGURE=		yes
#USE_LIBTOOL=		yes
USE_CMAKE=		yes

#WRKSRC=		${WRKDIR}/OpenCASCADE6.3.0/ros
USE_LANGUAGES=	c c++

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
