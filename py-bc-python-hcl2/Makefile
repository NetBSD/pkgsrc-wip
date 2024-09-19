# $NetBSD$

DISTNAME=	bc-python-hcl2-0.3.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bc-python-hcl2/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/amplify-education/python-hcl2
COMMENT=	Parser for HCL2
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lark-parser>=0.10.0:../../lang/py-lark-parser

# Only for Python 3.x
PYTHON_VERSIONS_INCOMPATIBLE+=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/hcl2tojson ${DESTDIR}${PREFIX}/bin/hcl2tojson${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
