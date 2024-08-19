# $NetBSD$

DISTNAME=	folly-2024.08.19.00
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/folly
COMMENT=	Open-source C++ library developed and used at Facebook
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
