# $NetBSD$

DISTNAME=	mount-zip-1.0.3
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/mount-zip/
COMMENT=	Read-only FUSE file system for ZIP archives
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
