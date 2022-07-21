# $NetBSD$

DISTNAME=	please-16.21.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=thought-machine/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thought-machine/please/
COMMENT=	High-performance extensible build system
LICENSE=	apache-2.0

#do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./bootstrap.sh

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
