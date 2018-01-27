# $NetBSD: Makefile,v 1.1 2013/09/13 18:56:59 jihbed Exp $

DISTNAME=	nipy-data-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	http://nipy.sourceforge.net/data-packages/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://neuroimaging.scipy.org
COMMENT=	Installation script for nipy data packages
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
DEPENDS+=       ${PYPKGPREFIX}-nipy>=0.3.0:../../wip/py-nipy
.include "../../mk/bsd.pkg.mk"
