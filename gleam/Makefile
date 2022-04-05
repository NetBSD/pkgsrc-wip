# $NetBSD$

GITHUB_PROJECT=	gleam
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	gleam-0.20.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=gleam-lang/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gleam-lang/gleam/
COMMENT=	Statically typed language for the Erlang VM
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/gleam-${PKGVERSION_NOREV}

.include "cargo-depends.mk"

USE_LANGUAGES=	c c++

DEPENDS+=	erlang>=20.0:../../lang/erlang

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gleam ${DESTDIR}${PREFIX}/bin

# \TODO: projects are compiled with rebar3 but there is no hard dependency
# on it. Should we bring it in as runtime dependency?
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
