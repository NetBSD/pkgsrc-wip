# $NetBSD$

DISTNAME=	harper-2.6.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Automattic/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Automattic/harper/
COMMENT=	English grammar checker
LICENSE=	apache-2.0

MAKE_ENV+=	CARGO_BUILD_JOBS=1
MAKE_ENV+=	RUSTFLAGS=-C codegen-units=1

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

CARGO_ARGS=	build --release -p harper-cli -p harper-ls

do-install:
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
		cargo install --path harper-cli --locked --root ${DESTDIR}${PREFIX}
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
		cargo install --path harper-ls --locked --root ${DESTDIR}${PREFIX}

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/.crates.toml
	${RM} -f ${DESTDIR}${PREFIX}/.crates2.json

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
