# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=	pyformex-0.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	graphics math python
MASTER_SITES=	http://download.savannah.gnu.org/releases/pyformex/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyformex.berlios.de/
COMMENT=	Tool to generate and manipulate complex 3D geometries
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-OpenGL>=3.0.1:../../graphics/py-OpenGL

USE_TOOLS+=	bash
USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-Numeric via py-OpenGL

REPLACE_BASH+=	pyformex-search

SUBST_CLASSES+=		suffix
SUBST_STAGE.suffix=	pre-configure
SUBST_SED.suffix+=	-e 's,python configure_py,python${PYVERSSUFFIX} configure_py,g'
SUBST_FILES.suffix+=	pyformex/lib/configure
SUBST_MESSAGE.suffix=	Fixing header search suffix.


.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
