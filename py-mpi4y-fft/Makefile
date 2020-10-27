# $NetBSD$

DISTNAME=	mpi4py-fft-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpi4py-fft/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/mpi4py/mpi4py-fft/src/master/
COMMENT=	Parallel Fast Fourier Transforms (FFTs) using MPI for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-mpi4py>=3.0.3:../../wip/py-mpi4py

BUILDLINK_API_DEPENDS.py-cython+=       ${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk""
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
