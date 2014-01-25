# $NetBSD: Makefile,v 1.5 2014/01/25 10:38:18 thomasklausner Exp $

DISTNAME=	gaphas-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/g/gaphas/
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gaphor.sourceforge.net/
COMMENT=	Gaphas is a GTK+ based diagramming widget
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.0:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-decorator>=3.2.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-simplegeneric>=0.8.1:../../wip/py-simplegeneric

PYTHON_VERSIONED_DEPENDENCIES=	cairo
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2

USE_LANGUAGES=	# none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
