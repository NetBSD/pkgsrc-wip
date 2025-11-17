# $NetBSD$

DISTNAME=	dblab-0.34.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=danvergara/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/danvergara/dblab/
COMMENT=	Simple command-line database client
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
