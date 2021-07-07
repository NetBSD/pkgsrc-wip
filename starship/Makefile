# $NetBSD$

DISTNAME=	starship-0.55.0
CATEGORIES=	shells
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=starship/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/starship/starship/
COMMENT=	Fast, customizable cross-shell prompt
LICENSE=	isc

# The libc and rust-battery crates currently have limited platform support
ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

LIBC_REV=	c4ae71f5e120336e50c84dbc80523efa3883d29e
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	libc-${LIBC_REV}.tar.gz
SITES.libc-${LIBC_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=rust-lang/}libc/archive/${LIBC_REV}.tar.gz

USE_LANGUAGES=			c
USE_TOOLS+=			pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}

# Disable rust-battery crate on NetBSD
# See https://github.com/svartalf/rust-battery/issues/20
CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		http
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
CARGO_FEATURES+=	battery
.endif

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

post-extract:
	mv ${WRKDIR}/libc-* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/starship ${DESTDIR}${PREFIX}/bin

DEPENDS+=		git-base-[0-9]*:../../devel/git-base

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
