# $NetBSD$

DISTNAME=	nanogrep-1.0.10
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uniminin/}
GITHUB_PROJECT=	nanogrep
GITHUB_TAG=	9441de53c3512175ecfd51f262efcf9543ce7815

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Uniminin/nanogrep/
COMMENT=	Custom Implementation of minigrep with additional functionality
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ng ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
