# $NetBSD$

DISTNAME=	aichat-0.21.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sigoden/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/sigoden/aichat
COMMENT=	All-in-one AI CLI tool
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/aichat ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
