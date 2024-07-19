# $NetBSD$

DISTNAME=	v22.01-v1.5.5-R3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=mcmilk/}
GITHUB_PROJECT=	7-Zip-zstd
GITHUB_TAG=	v22.01-v1.5.5-R3
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mcmilk/7-Zip-zstd/
COMMENT=	7-zip with support for additional codecs
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/7-Zip-zstd-22.01-v1.5.5-R3
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

BUILD_DIRS+=	CPP/7zip/Bundles/Alone2
MAKE_FILE=	makefile.gcc

# Disable -Werror.
MAKE_FLAGS+=	CFLAGS_WARN_WALL=${CFLAGS:Q}

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

# Disable RAR archive file support licensed under unRAR license.
# You can see file listing and extract files without compression.
BUILD_MAKE_FLAGS+=	DISABLE_RAR_COMPRESS=1

INSTALLATION_DIRS+=	bin

# Fix parallel build
pre-build:
	${MKDIR} ${WRKSRC}/CPP/7zip/Bundles/Alone2/_o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CPP/7zip/Bundles/Alone2/_o/7zz \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
