# $NetBSD: Makefile,v 1.1.1.1 2003/11/23 01:07:49 mpasternak Exp $
#

PKGNAME=	${PYPKGPREFIX}-vtkmodule-${VTK_VERSION}

PYDISTUTILSPKG=	# defined
PYSETUPSUBDIR=	Wrapping/Python/

VTK_CMAKE_OPT=	-DPYTHON_INCLUDE_PATH:STRING=${PREFIX}/${PYINC} \
		-DPYTHON_LIBRARY:STRING=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so \
		-DVTK_WRAP_PYTHON:BOOL=ON

DEPENDS=	vtk-python>=4.2:../../wip/vtk-python

.include "../../wip/vtk/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
