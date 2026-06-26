# $NetBSD$

DISTNAME=	pitchfork-cli-2.14.0
#DISTNAME=	pitchfork-2.14.0
CATEGORIES=	sysutils
#MASTER_SITES=	${MASTER_SITE_GITHUB:=endevco/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	https://static.crates.io/crates/pitchfork-cli/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pitchfork.en.dev/
COMMENT=	Devilishly good process manager for developers
LICENSE=	mit

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
