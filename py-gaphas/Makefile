# $NetBSD: Makefile,v 1.8 2014/06/01 12:49:41 thomasklausner Exp $

DISTNAME=	gaphas-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gaphas/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://gaphor.sourceforge.net/
COMMENT=	Gaphas is a GTK+ based diagramming widget
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.0:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-decorator>=3.2.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-simplegeneric>=0.8.1:../../wip/py-simplegeneric
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
