# $NetBSD$

DISTNAME=	bc-python-hcl2-0.3.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGVERSION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bc-python-hcl2/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/amplify-education/python-hcl2
COMMENT=	Parser for HCL2
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-lark-parser>=0.7.8:../../wip/py-lark-parser

post-extract:
	${MV} ${WRKSRC}/bin/hcl2tojson ${WRKSRC}/bin/hcl2tojson${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
