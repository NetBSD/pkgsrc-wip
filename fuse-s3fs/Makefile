# $NetBSD$

DISTNAME=	fuse-s3fs-${PKGVERSION}
PKGVERSION=	1.93
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=s3fs-fuse/}
GITHUB_PROJECT=	s3fs-fuse
GITHUB_TAG=	v${PKGVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/s3fs-fuse/s3fs-fuse
COMMENT=	FUSE file-system and utilities for S3-compatible APIs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoheader automake autoreconf gmake pkg-config

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../filesystems/fuse/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
