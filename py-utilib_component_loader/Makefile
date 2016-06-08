# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	pyutilib.component.loader-3.2.3
PKGNAME=	${PYPKGPREFIX}-utilib_component_loader-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyutilib.component.loader/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://software.sandia.gov/trac/pyutilib
COMMENT=	PyUtilib plugins for loading external packages
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-utilib_component_config>=${VERSION}:../../wip/py-utilib_component_config
#DEPENDS+=	${PYPKGPREFIX}-utilib_component_core>=3.0.4:../../wip/py-utilib_component_core

WRKSRC=		${WRKDIR}/pyutilib.component.loader-3.2.3

VERSION=	3.2.3
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
