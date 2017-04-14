# $NetBSD: Makefile,v 1.2 2015/08/05 22:19:29 jihbed Exp $

DISTNAME=	stevedore-1.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stevedore/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dreamhost/stevedore
COMMENT=	Manage dynamic plugins for Python applications
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pbr>=2.0.0:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
