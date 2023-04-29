# $NetBSD$

DISTNAME=	git-cinnabar-0.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=glandium/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/glandium/git-cinnabar/
COMMENT=	Remote helper to use mercurial repositories with git
LICENSE=	mpl-2.0 AND gnu-gpl-v2

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_TOOLS+=	gmake

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE}

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
