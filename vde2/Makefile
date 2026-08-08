# $NetBSD$

DISTNAME=	vde2-2.3.3.0.0.2026.08.03
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=virtualsquare/}
GITHUB_PROJECT=	vde-2
GITHUB_TAG=	6f1a656584397fc46705ff3d6fbbd3edc2f50f0c
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/virtualsquare/vde-2/
COMMENT=	Virtual Distributed Ethernet
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/lib/vdehist.pc.in
PKGCONFIG_OVERRIDE+=	src/lib/vdemgmt/vdemgmt.pc.in
PKGCONFIG_OVERRIDE+=	src/lib/vdeplug.pc.in
PKGCONFIG_OVERRIDE+=	src/lib/vdesnmp.pc.in

.include "../../devel/cmake/build.mk"
.include "../../security/wolfssl/buildlink3.mk" #optional
.include "../../mk/bsd.pkg.mk"
