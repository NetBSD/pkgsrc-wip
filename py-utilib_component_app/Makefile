# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:06:54 jihbed Exp $
#

DISTNAME=	pyutilib.component.app-3.1.3
PKGNAME=	${PYPKGPREFIX}-utilib_component_app-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutilib.component.app/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://software.sandia.gov/trac/pyutilib
COMMENT=	Application interface for the PyUtilib Component Architecture
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-utilib_component_core>=3.0.4:../../wip/py-utilib_component_core

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyutilib.component.app-3.1.3

VERSION=	1.0.5
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
