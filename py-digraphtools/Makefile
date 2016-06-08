# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:21 asau Exp $
#

DISTNAME=	digraphtools-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/digraphtools/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/dbasden/python-digraphtools
COMMENT=	Python library for working with directed acyclic graphs
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/digraphtools-0.2.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
