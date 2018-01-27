# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	pysage-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	parallel python
MASTER_SITES=	http://pysage.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/pysage/
COMMENT=	High-level message passing library supporting actor based concurrency
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-processing>=0.52:../../wip/py-processing

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
