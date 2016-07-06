# $NetBSD$

DISTNAME=	FreeCAD-0.16
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=FreeCAD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freecadweb.org
COMMENT=	General purpose feature-based, parametric 3D modeler
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/FreeCAD-0.16
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config bash
USE_LANGUAGES=	c c++ fortran

PKGCONFIG_OVERRIDE+=	src/Mod/Robot/App/kdl_cp/kdl.pc.in

# Fix this
.include "../../wip/py-pyside-shiboken/buildlink3.mk"
.include "../../graphics/Coin/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../wip/oce/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
