# $NetBSD$

DISTNAME=	mount-zip-1.0.3
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/mount-zip/
COMMENT=	Read-only FUSE file system for ZIP archives
LICENSE=	gnu-gpl-v3

# TODO: We should support c++20 in USE_LANGUAGES. Maybe we should do
# GCC_REQD+=8 automatically too, because GCC 8.0 is the first version
# supporting *some* part of C++20?
USE_LANGUAGES=	c++
# GCC 8.4.0 is not good enough for this particular package. But pho@
# doesn't know which one is the exact minimum. It's somewhere between
# 8.4 < x <= 9.
GCC_REQD+=	9
USE_TOOLS+=	gmake pkg-config

# TODO: mk/fuse.buildlink3.mk does this for CFLAGS.NetBSD, but it's
# actually a preprocessor flag so pho@ thinks it's wrong. pho@ just
# doesn't want to touch any mk/* in the pre-freeze phase.
CPPFLAGS.NetBSD+=	-D_KERNTYPES
# TODO: The underlying problem is that our <puffs.h> #include's
# <fs/puffs/puffs_msgif.h> and exposes kernel types, and thus
# -D_KERNTYPES is required to use the header. This too needs to be
# fixed.

# GCC < 10 doesn't support -std=c++20. Use c++2a instead.
BUILDLINK_TRANSFORM+=	opt:-std=c++20:-std=c++2a

# Required for generating a man page.
# TODO: Pandoc is not portable enough, because GHC isn't. We should
# probably put a pre-generated man page in ${FILESDIR}.
BUILD_DEPENDS+=	pandoc-[0-9]*:../../converters/pandoc

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	bindir=${PREFIX:Q}/bin
INSTALL_MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
INSTALL_MAKE_FLAGS+=	INSTALL_DATA=${INSTALL_DATA:Q}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}/man1

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
