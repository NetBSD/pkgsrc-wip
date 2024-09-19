# $NetBSD$

VERS=		1.1.0
DISTNAME=	IoTPy-${VERS}
PKGNAME=	${PYPKGPREFIX}-ioTPy-${VERS}
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=I/${DISTNAME:S/${VERS}//}/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/AssembleSoftware/IoTPy
COMMENT=	Helps you to build applications that operate on streams of data.
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_ABI_DEPENDS.py-numpy?=	${PYPKGPREFIX}-numpy>=1.19.2nb1
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
