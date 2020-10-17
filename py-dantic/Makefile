# $NetBSD$

DISTNAME=	pydantic-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/80/0a/75c950d621652f7d626225c1d8275d15e9119548b6faa7d0485a253ff181/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/samuelcolvin/pydantic
COMMENT=	Data validation and settings management using python 3.6 type hinting
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-dataclasses>=0.6;python_version<"3.7":../../wip/py-dataclasses

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
