# $NetBSD$

DISTNAME=	elvish-0.21.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=elves/}
GITHUB_TAG=	e022a729b037a677990c843f47fc37dc48f58473

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
