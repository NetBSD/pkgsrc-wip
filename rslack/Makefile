# $NetBSD$

DISTNAME=	rslack-0.2.4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=kohbis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kohbis/rslack/
COMMENT=	TUI for posting message to Slack
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rslack \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
