# $NetBSD$

DISTNAME=	weave-0.5.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ataraxy-Labs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ataraxy-Labs/weave/
COMMENT=	Entity-level git merge driver
LICENSE=	mit OR apache-2.0

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/weave ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/weave-driver ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/weave-github ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/weave-mcp ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
