# $NetBSD$

DISTNAME=	forgejo-cli-0.5.0
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/forgejo-contrib/forgejo-cli/archive/
SITES.${DISTNAME}.tar.gz=	-${MASTER_SITES}v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/forgejo-contrib/forgejo-cli
COMMENT=	CLI application for interacting with Forgejo
LICENSE=	apache-2.0 OR mit

WRKSRC=		${WRKDIR}/${PKGBASE}

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
