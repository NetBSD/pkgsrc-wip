# $NetBSD: Makefile,v 1.1 2015/06/01 22:48:21 jihbed Exp $

DISTNAME=	baron-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/baron/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Psycojoker/baron
COMMENT=	Full Syntax Tree for python to make writing refactoring code
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-rply>=0.7.3:../../devel/py-rply

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
