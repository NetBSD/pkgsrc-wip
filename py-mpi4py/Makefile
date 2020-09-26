# $NetBSD$

DISTNAME=	mpi4py-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	https://files.pythonhosted.org/packages/ec/8f/bbd8de5ba566dd77e408d8136e2bab7fdf2b97ce06cab830ba8b50a2f588/

MAINTAINER=     jihbed.research@gmail.com
HOMEPAGE=       https://bitbucket.org/mpi4py/mpi4py/
COMMENT=        MPI for Python - Python bindings for MPI
LICENSE=        modified-bsd


.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
