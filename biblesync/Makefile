# $NetBSD$

DISTNAME=	biblesync-2.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=karlkleinpaste/}
GITHUB_TAG=	${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	ktnb@NetBSD.net
HOMEPAGE=	https://github.com/karlkleinpaste/biblesync/
COMMENT=	Multicast shared co-navigation library for Bible programs
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/biblesync-2.1.0
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	biblesync.pc.in

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=TRUE

.include "../../devel/cmake/build.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
