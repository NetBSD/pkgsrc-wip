# $NetBSD$

DISTNAME=	cskk-3.1.2
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=naokiri/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://github.com/naokiri/cskk
COMMENT=	Cobalt SKK library
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	cargo-c-[0-9]*:../../devel/cargo-c

.include "cargo-depends.mk"

INSTALLATION_DIRS=	include/cskk lib/cskk lib/pkgconfig share/libcskk

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxkbcommon}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libxkbcommon}/lib
CARGOC_ARGS=	--verbose --release --destdir ${DESTDIR} --prefix ${PREFIX}

do-build:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/cargo-cbuild cbuild ${CARGOC_ARGS}

do-install:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/cargo-cinstall cinstall ${CARGOC_ARGS}

.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
