# $NetBSD$

DISTNAME=	rsClock-0.1.4
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=valebes/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/valebes/rsClock/
COMMENT=	Simple terminal clock
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rsclock ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
