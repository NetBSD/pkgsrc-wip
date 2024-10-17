# $NetBSD$

DISTNAME=	chezmoi-2.52.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=twpayne/}
GITHUB_PROJECT=	chezmoi
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pickles@tilde.pink
HOMEPAGE=	https://www.chezmoi.io/
COMMENT=	Manage your dotfiles across multiple diverse machines
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
DEPENDS+=	git-base>=0:../../devel/git-base
DEPENDS+=	age>=0:../../security/age

.include "go-modules.mk"

GO_BUILD_PATTERN=	-trimpath -mod=readonly -tags noupgrade -ldflags "-X github.com/twpayne/chezmoi.cmd.DocsDir=/usr/pkg/share/doc/${GITHUB_PROJECT} -X main.version=${PKGVERSION_NOREV}"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/chezmoi ${DESTDIR}${PREFIX}/bin/chezmoi
	mkdir -p ${DESTDIR}${PREFIX}/share/doc/chezmoi
	${INSTALL_DATA} ${WRKSRC}/assets/chezmoi.io/docs/*md ${DESTDIR}${PREFIX}/share/doc/chezmoi/

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
