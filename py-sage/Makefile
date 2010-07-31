# $NetBSD: Makefile,v 1.3 2010/07/31 11:58:20 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
