# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:09:37 jihbed Exp $
#

DISTNAME=	pyutilib.component.loader-3.2.3
PKGNAME=	${PYPKGPREFIX}-utilib_component_loader-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutilib.component.loader/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://software.sandia.gov/trac/pyutilib
COMMENT=	PyUtilib plugins for loading external packages
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-utilib_component_config>=${VERSION}:../../wip/py-utilib_component_config
#DEPENDS+=	${PYPKGPREFIX}-utilib_component_core>=3.0.4:../../wip/py-utilib_component_core

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyutilib.component.loader-3.2.3

VERSION=	3.2.3
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
