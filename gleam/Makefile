# $NetBSD$

GITHUB_PROJECT=	gleam
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	gleam-0.21.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=gleam-lang/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gleam-lang/gleam/
COMMENT=	ML-flavoured type-safe language using the BEAM runtime
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/gleam-${PKGVERSION_NOREV}

.include "cargo-depends.mk"

USE_LANGUAGES=	c c++

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gleam ${DESTDIR}${PREFIX}/bin

do-test:
	(cd ${WRKSRC} && ${DESTDIR}${PREFIX}/bin/gleam new hello && cd hello && ${DESTDIR}${PREFIX}/bin/gleam test)

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
