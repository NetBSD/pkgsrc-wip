# $NetBSD$
#

DISTNAME=	cli-1.6.17
PKGNAME=	go-transifex-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/transifex/cli
COMMENT=	Command line interface for Transifex
LICENSE=	apache-2.0

SUPERSEDES+=	py31[0-9]-transifex-client-[0-9]*

.include "go-modules.mk"

pre-install:
	cd ${WRKDIR}/.gopath/bin && ${MV} cli tx

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
