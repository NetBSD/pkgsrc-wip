# $NetBSD$

DISTNAME=	quest-tui-0.1.1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=frustak/}
GITHUB_PROJECT=	Quest
GITHUB_TAG=	7e696c63216ee50920b498e759de82d6e61210f8

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/frustak/Quest/
COMMENT=	Rust todo TUI
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/quest-tui ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
