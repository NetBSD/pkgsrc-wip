# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:31 ykomatsu Exp $
#

DISTNAME=		MayaVi-1.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mayavi/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mayavi.sourceforge.net/
COMMENT=		Scientific data visualizer written in Python

DEPENDS=	${PYPKGPREFIX}-vtkmodule>=4.2:../../graphics/vtk-python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
