# $NetBSD: Makefile,v 1.1 2015/07/04 03:16:07 jihbed Exp $

DISTNAME=	GitPython-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GitPython/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gitpython-developers/GitPython
COMMENT=	Python Git Library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-gitdb>=0.6.4:../../wip/py-gitdb

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
