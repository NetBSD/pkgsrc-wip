# $NetBSD$

DISTNAME=	git-cinnabar-0.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=glandium/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/glandium/git-cinnabar/
COMMENT=	Remote helper to use mercurial repositories with git
LICENSE=	mpl-2.0 AND gnu-gpl-v2

.include "cargo-depends.mk"

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_TOOLS+=	gmake pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib

#do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE}

.include "../../lang/rust/cargo.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
