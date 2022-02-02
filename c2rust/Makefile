# $NetBSD$

DISTNAME=	c2rust-0.15.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=immunant/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c2rust.com/
COMMENT=	Translate C modules into semantically equivalent Rust code
LICENSE=	modified-bsd

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	examples/json-c/repo/json-c.pc.in

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
