# $NetBSD$

DISTNAME=	rusty-rain-0.3.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=cowboy8625/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://rusty-rain.xyz/
COMMENT=	Cross Platform Matrix Rain made with Rust
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rusty-rain ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
