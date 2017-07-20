# $NetBSD: Makefile,v 1.13 2017/06/19 18:41:39 maya Exp $
#

DISTNAME=	cryfs-0.9.7
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=cryfs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cryfs.org/
COMMENT=	FUSE Encrypted Filesystem
LICENSE=	gnu-lgpl-v3
EXTRACT_USING=	bsdtar

GITHUB_PROJECT=	cryfs

USE_TOOLS+=	autoconf cmake pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

#TEST_TARGET=	test

REPLACE_PYTHON=	src/gitversion/*.py

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../security/crypto++/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
