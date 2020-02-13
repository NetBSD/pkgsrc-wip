# $NetBSD$

DISTNAME=	gh-0.5.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cli/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cli.github.com/
COMMENT=	GitHub CLI
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME:S/gh/cli/}
GO_SRCPATH=	github.com/cli/cli

DEPENDS+=		git-base-[0-9]*:../../devel/git-base

CHECK_RELRO_SKIP+=	bin/gh

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/gh ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
