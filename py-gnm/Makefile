# $NetBSD: Makefile,v 1.1.1.1 2011/01/24 09:01:26 jihbed Exp $
#

DISTNAME=	pygnm-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	biology python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pygnm/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.pitt.edu/~ahb12
COMMENT=	Python Gaussian Network Model
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pygnm-0.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
