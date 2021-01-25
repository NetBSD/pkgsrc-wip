# $NetBSD$

DISTNAME=	sfm-0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Harunx9/}
GITHUB_PROJECT=	sfm
GITHUB_TAG=	f19686ff7e35c496d0caad5ce35005854c7d04ae

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Harunx9/sfm/
COMMENT=	Simple file manager
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin share/doc/sfm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sfm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/sfm

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
