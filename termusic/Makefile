# $NetBSD$

DISTNAME=	termusic-0.2.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=tramhao/}
GITHUB_PROJECT=	termusic
GITHUB_TAG=	2e1f45aa57b409bf023944aca7835c27ed8bdc47

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tramhao/termusic/
COMMENT=	Music Player TUI written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mpv}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.mpv}/lib
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/termusic ${DESTDIR}${PREFIX}/bin

DEPENDS+=	youtube-dl-[0-9]*:../../net/youtube-dl

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../multimedia/mpv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
