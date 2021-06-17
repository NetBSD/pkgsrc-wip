# $NetBSD$

DISTNAME=	starship-0.54.0
CATEGORIES=	shells
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=starship/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/starship/starship/
COMMENT=	Fast, customizable cross-shell prompt
LICENSE=	isc

# The libc and rust-battery crates currently have limited platform support
ONLY_FOR_PLATFORM=Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-* 

USE_LANGUAGES=	c
RUST_REQ?=	1.51.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/starship ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
