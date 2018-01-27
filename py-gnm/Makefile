# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:41 asau Exp $
#

DISTNAME=	pygnm-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygnm/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.pitt.edu/~ahb12
COMMENT=	Python Gaussian Network Model
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/pygnm-0.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
