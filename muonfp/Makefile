# $NetBSD$

DISTNAME=	muonfp-1.5.0
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sundruid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-security@NetBSD.org
HOMEPAGE=	https://github.com/sundruid/muonfp/
COMMENT=	TCP passive fingerprinter
LICENSE=	mit

#WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
