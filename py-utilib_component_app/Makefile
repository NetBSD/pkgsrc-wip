# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	pyutilib.component.app-3.1.3
PKGNAME=	${PYPKGPREFIX}-utilib_component_app-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyutilib.component.app/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://software.sandia.gov/trac/pyutilib
COMMENT=	Application interface for the PyUtilib Component Architecture
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-utilib_component_core>=3.0.4:../../wip/py-utilib_component_core

WRKSRC=		${WRKDIR}/pyutilib.component.app-3.1.3

VERSION=	1.0.5
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
