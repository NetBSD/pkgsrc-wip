# $NetBSD$

DISTNAME=	scc-3.0.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=boyter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/boyter/scc
COMMENT=	Count physical lines of code in many programming languages
LICENSE=	mit OR unlicense

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/scc ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
