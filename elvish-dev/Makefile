# $NetBSD$

DISTNAME=	elvish-0.20.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=elves/}
GITHUB_TAG=	a1bfc0e2318f91f15ef07d1f40eae0bb9240b501

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://elv.sh/
COMMENT=	Expressive programming language and a versatile interactive shell
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	bin
PKG_SHELL=		bin/elvish

USE_TOOLS+=		perl gmake

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/elvish \
		${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
