# $NetBSD: Makefile,v 1.2 2005/04/16 13:33:28 thomasklausner Exp $
#

PKGNAME=	${PYPKGPREFIX}-vtkmodule-${VTK_VERSION}

PYDISTUTILSPKG=	# defined
PYSETUPSUBDIR=	Wrapping/Python/

VTK_CMAKE_OPT=	-DPYTHON_INCLUDE_PATH:STRING=${PREFIX}/${PYINC} \
		-DPYTHON_LIBRARY:STRING=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so \
		-DVTK_WRAP_PYTHON:BOOL=ON

DEPENDS=	vtk-python>=4.2:../../graphics/vtk-python

.include "../../graphics/vtk/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
