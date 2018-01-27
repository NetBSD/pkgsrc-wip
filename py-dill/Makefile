# $NetBSD$

DISTNAME=	dill-0.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dill/}
EXTRACT_SUFX=	.tgz#md5=8e7d1ec5a0f150b536da4d0623c3931b

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.cacr.caltech.edu/~mmckerns/dill.htm
COMMENT=	Utility for serialization of python objects
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/readline

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	32 34 35 36

	
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
