# $NetBSD$

DISTNAME=	mpi4py-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=   ${MASTER_SITE_PYPI:=m/mpi4py}

MAINTAINER=     jihbed.research@gmail.com
HOMEPAGE=       https://bitbucket.org/mpi4py/mpi4py/
COMMENT=        MPI for Python - Python bindings for MPI
LICENSE=        modified-bsd


.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
