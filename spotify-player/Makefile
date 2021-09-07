# $NetBSD$

DISTNAME=	spotify-player-0.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=aome510/}
GITHUB_PROJECT=	spotify-player
GITHUB_TAG=	3af23a2e2f8861fc6fa37ba13d57aff5bcd6d752

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/aome510/spotify-player/
COMMENT=	Command driven spotify player
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/spotify_player ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
