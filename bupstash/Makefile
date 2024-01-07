# $NetBSD$

DISTNAME=	bupstash-0.12.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=andrewchambers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andrewchambers/bupstash
COMMENT=	Easy and efficient encrypted backups
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libsodium}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL} ${WRKSRC}/target/release/bupstash \
		${DESTDIR}/${PREFIX}/bin/bupstash

.include "../../lang/rust/cargo.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
