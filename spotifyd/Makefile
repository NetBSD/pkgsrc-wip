# $NetBSD$

DISTNAME=	spotifyd-0.3.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Spotifyd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	https://github.com/Spotifyd/spotifyd/
COMMENT=	Open source Spotify client running as a UNIX daemon
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

#INSTALLATION_DIRS+=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/spotifyd ${DESTDIR}${PREFIX}/bin

.include "options.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
