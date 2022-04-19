# $NetBSD: Makefile,v 1.18 2018/03/12 11:17:42 wiz Exp $

DISTNAME=	zipfs-0.0
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_GITHUB:=lapinott/}
GIT_REPO=	https://github.com/lapinott/zipfs.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lapinott/zipfs
COMMENT=	Utility library for zipfs
LICENSE=	mit

WRKSRC=			${WRKDIR}/zipfs

CPPFLAGS+=	-I${BUILDLINK_PREFIX.libzip}/include
CFLAGS+=	-I${BUILDLINK_PREFIX.libzip}/include

USE_CMAKE=	yes
USE_LANGUAGES=	c c++17
CMAKE_ARGS+=	-DBOOST_DIR=${BUILDLINK_PREFIX.boost-libs}
CMAKE_ARGS+=	-DLIBZIP_DIR=${BUILDLINK_PREFIX.libzip}

.include "../../wip/mk/git-package.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/lapinott-util-git/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
