# $NetBSD$

DISTNAME=	bookokrat-0.3.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bugzmanov/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bugzmanov/bookokrat
COMMENT=	Terminal based epub reader
#LICENSE=	agpl-3.0

RUST_REQ=	1.86
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/${BUILDLINK_LIBDIRS.fontconfig}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bookokrat \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
