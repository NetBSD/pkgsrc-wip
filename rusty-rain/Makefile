# $NetBSD$

DISTNAME=	rusty-rain-0.2.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=cowboy8625/}
GITHUB_PROJECT=	rusty-rain
GITHUB_TAG=	86b9fd6ac6bafef83b1bc7136b1a299a62097155

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/cowboy8625/rusty-rain/
COMMENT=	Cross Platform Matrix Rain made with Rust
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rusty-rain ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
