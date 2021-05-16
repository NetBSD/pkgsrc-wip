# $NetBSD$

DISTNAME=	deckster-0.2.1
CATEGORIES=	misc
MASTER_SITES=	https://gitlab.com/prince_bett/deckster/-/archive/${GIT_TAG}/
GIT_TAG=	fcff34b083963d9738a00b8a9002ac33864a756f

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://gitlab.com/prince_bett/deckster/
COMMENT=	TUI to study flashcards in the terminal
LICENSE=	mit

WRKSRC=		${WRKDIR}/deckster-fcff34b083963d9738a00b8a9002ac33864a756f

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/deckster ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
