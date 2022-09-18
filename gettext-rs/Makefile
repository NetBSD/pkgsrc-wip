# $NetBSD$

DISTNAME=	gettext-rs-0.7.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Koka/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Koka/gettext-rs/
COMMENT=	GNU Gettext FFI binding for Rust
LICENSE=	mit

# gettext-rs = { version = "0.7", features = ["gettext-system"] }
#CARGO_FEATURES=	gettext-system

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

MAKE_ENV+=	GETTEXT_DIR=${PREFIX}
MAKE_ENV+=	GETTEXT_SYSTEM=enabled

TOOL_DEPENDS+=	gettext-tools>=0.19.4nb1:../../devel/gettext-tools

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
