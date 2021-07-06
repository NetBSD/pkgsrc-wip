# $NetBSD$

DISTNAME=		lazygit-${GITHUB_TAG}
PKGNAME=		go-lazygit-${VERSION}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=jesseduffield/}
GITHUB_PROJECT=		lazygit
VERSION=		0.28.2
GITHUB_TAG=		v${VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/jesseduffield/lazygit/
COMMENT=		Simple terminal UI for git commands
LICENSE=		mit

GO_BUILD_PATTERN=	github.com/jesseduffield/lazygit

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/lazygit ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
