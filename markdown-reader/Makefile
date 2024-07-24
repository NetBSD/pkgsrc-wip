# $NetBSD$

DISTNAME=	markdown-reader-0.1.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=joshka/}
GITHUB_PROJECT=	tui-markdown
GITHUB_TAG=	markdown-reader-v0.1.12

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/joshka/tui-markdown/
COMMENT=	Simple markdown reader
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/mdr \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
