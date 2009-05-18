# $NetBSD: Makefile,v 1.2 2009/05/18 21:51:41 jihbed Exp $
#

DISTNAME=	pysage-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://pysage.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/pysage/
COMMENT=	High-level message passing library supporting actor based concurrency
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
