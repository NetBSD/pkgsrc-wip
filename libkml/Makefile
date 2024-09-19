# $NetBSD$

GITHUB_PROJECT=	libkml
GITHUB_TAG=	refs/tags/1.3.0
DISTNAME=	1.3.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=libkml/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/libkml/libkml/
COMMENT=	Google's reference implementation of OGC KML 2.2.
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/libkml-1.3.0
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	cmake/libkml.pc.in

.include "../../textproc/uriparser/buildlink3.mk"
.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
