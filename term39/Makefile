# $NetBSD$

DISTNAME=	term39-0.20.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=alejandroqh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alejandroqh/term39/
COMMENT=	Retro styled terminal multiplexer
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"
.include "../../mk/bsd.prefs.mk"

CARGO_NO_DEFAULT_FEATURES=	yes

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin"
CARGO_FEATURES+=	bsd
.elif ${OPSYS} == "Linux"
CARGO_FEATURES+=	full
.else
CARGO_FEATURES+=	tty
.endif

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.clang}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.clang}/lib

BUILDLINK_DEPMETHOD.clang=      build
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
