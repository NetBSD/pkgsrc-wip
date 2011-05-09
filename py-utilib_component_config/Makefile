# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:07:42 jihbed Exp $
#

DISTNAME=	pyutilib.component.config-3.2.3
PKGNAME=	${PYPKGPREFIX}-utilib_component_config-${VERSION}
CATEGORIES=	math devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutilib.component.config/


MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/p/pyutilib.component.config/
COMMENT= Extensions for configuring components in the PyUtilib Component Architecture
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-utilib_component_core>=3.0.4:../../wip/py-utilib_component_core

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyutilib.component.config-3.2.3

VERSION=	3.2.3
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
