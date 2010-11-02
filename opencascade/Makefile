# $NetBSD: Makefile,v 1.1 2010/11/02 13:24:38 silasdb Exp $
#

OPENCASCADE_VERSION=6.3

DISTNAME=	OpenCASCADE_src
PKGNAME=	opencascade-${OPENCASCADE_VERSION}
CATEGORIES=	cad
MASTER_SITES=	http://files.opencascade.com/OCC_6.3_release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	silasdb@gmail.com
HOMEPAGE=	http://www.opencascade.org/
COMMENT=	Software development platform for 3D CAD CAM CAE

LICENSE=	opencascade-license
LICENSE_FILE=	opencascade-license

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE_PREFIX=	${PREFIX}/opencascade

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

WRKSRC=		${WRKDIR}/OpenCASCADE6.3.0/ros
USE_LANGUAGES=	c c++

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
