# $NetBSD$

DISTNAME=	ast-grep-0.11.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ast-grep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ast-grep.github.io/
COMMENT=	CLI tool for code structrual search, lint and rewriting
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

# FIXME: It would be nice if this can be automatically handled, please see TODO
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ast-grep ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sg ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
