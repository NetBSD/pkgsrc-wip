# $NetBSD: Makefile,v 1.2 2003/12/30 23:57:35 cjep Exp $
#

PKGNAME=	vtk-python-${VTK_VERSION}

COMMENT=	Python wrapper libraries for vtk; see vtk package for details

VTK_CMAKE_OPT=  -DPYTHON_INCLUDE_PATH:STRING=${PREFIX}/${PYINC} \
		-DPYTHON_LIBRARY:STRING=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so \
		-DVTK_WRAP_PYTHON:BOOL=ON

PYTHON_VERSION_REQUIRED=	23pth

VTK_PY_LIBS=	bin/libvtkCommonPython.so \
		bin/libvtkFilteringPython.so \
		bin/libvtkImagingPython.so \
		bin/libvtkGraphicsPython.so \
		bin/libvtkIOPython.so \
		bin/libvtkRenderingPython.so \
		bin/libvtkRenderingPythonTkWidgets.so

do-build:
	cd ${WRKSRC} && ${MAKE} default_target_Wrapping_Python

do-install:
	for lib in ${VTK_PY_LIBS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/$$lib ${VTK_LIBDIR}; \
	done

DEPENDS=	vtk>=${VTK_VERSION}:../../wip/vtk

.include "../../wip/vtk/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
