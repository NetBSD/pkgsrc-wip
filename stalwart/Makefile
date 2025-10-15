# $NetBSD$

DISTNAME=	stalwart-0.13.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=stalwartlabs/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://stalw.art/
COMMENT=	open-source mail & collaboration server 
LICENSE=	gnu-agpl-v3

## See also
## <https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=286326>
## <https://aur.archlinux.org/packages/stalwart-mail-server>

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

PKG_CC=			clang
PKG_CXX=		clang++

.include "../../lang/clang/buildlink3.mk"
.include "../../mk/compiler/clang.mk"

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"

.include "../../mk/bsd.pkg.mk"
