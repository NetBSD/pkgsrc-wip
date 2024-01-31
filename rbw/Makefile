# $NetBSD$

DISTNAME=	rbw-1.9.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=doy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doy/rbw/
COMMENT=	Unofficial bitwarden cli
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

post-patch:
	${CP} ${FILESDIR}/netbsd.rs ${WRKDIR}/vendor/region-3.0.0/src/os/

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
