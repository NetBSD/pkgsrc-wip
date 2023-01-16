# $NetBSD$

DISTNAME=	v0.0.25
PKGNAME=	gospt-0.0.25
CATEGORIES=	audio
MASTER_SITES=	https://gitea.asdf.cafe/abs3nt/gospt/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitea.asdf.cafe/abs3nt/gospt/
COMMENT=	Spotify TUI and CLI
LICENSE=	mit

# gospt is not really a Spotify client but, more of a controller.
# You will need a client like 'librespot' or 'spotifyd' running in
# the backgroud and to set that as device in gospt.

WRKSRC=		${WRKDIR}/gospt

INSTALLATION_DIRS=	bin
GO_BUILD_PATTERN=	./...

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/gospt \
		${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
