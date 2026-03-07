# $NetBSD$

DISTNAME=	mpi4py-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=   ${MASTER_SITE_PYPI:=m/mpi4py/}

MAINTAINER=     matthewd@fastmail.us
HOMEPAGE=       https://mpi4py.github.io/mpi4py/stable/
COMMENT=        MPI for Python - Python bindings for MPI
LICENSE=        modified-bsd

.include "../../lang/python/pyversion.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68.2:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-colorlog>=6.10.1:../../devel/py-colorlog

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
