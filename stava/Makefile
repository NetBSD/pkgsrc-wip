# $NetBSD$

DISTNAME=	stava-0.6.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=simeg/}
GITHUB_PROJECT=	stava
GITHUB_TAG=	414b4a5826eb1039d3db34b3a52febf0baaaa720

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/simeg/stava/
COMMENT=	CLI spell checker
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stava ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
