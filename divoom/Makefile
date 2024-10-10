# $NetBSD$

DISTNAME=	divoom-0.1.42
PKGREVISION=	1
CATEGORIES=	net graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=r12f/}
#GITHUB_TAG=	${PKGVERSION_NOREV}
# post 0.1.42 patch to fix build problem in tokio-cron-scheduler
GITHUB_TAG=	d35fc8706968b55d22d6d74d1e8d6c7facdf7f0b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/r12f/divoom/
COMMENT=	Rust Library for controlling divoom devices that support REST APIs
LICENSE=	apache-2.0

USE_LANGUAGES=	c
USE_TOOLS+=	gmake perl pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/divoom-cli ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/divoom-gateway ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
