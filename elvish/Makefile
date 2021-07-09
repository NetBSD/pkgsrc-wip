# $NetBSD$

DISTNAME=	elvish-0.15.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=elves/}
CATEGORIES=	shells

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://elv.sh/
COMMENT=	Expressive programming language and a versatile interactive shell
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

GO_VERSION_DEFAULT=	115

INSTALLATION_DIRS=	bin
PKG_SHELL=		bin/elvish

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/elvish ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
