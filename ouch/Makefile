# $NetBSD$

DISTNAME=	ouch-0.5.1.20250214
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=ouch-org/}
#GITHUB_TAG=	${PKGVERSION_NOREV}
GITHUB_TAG=	ecc05cdd60dc7e180ddf10a2e6a3c6bcea475321

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ouch-org/ouch/
COMMENT=	Painless compression and decompression in the terminal
LICENSE=	mit AND gnu-lgpl-v3

USE_LANGUAGES=	c c++

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
# links against libclang?!
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
