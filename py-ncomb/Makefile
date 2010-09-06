# $NetBSD: Makefile,v 1.1.1.1 2010/09/06 16:42:10 jihbed Exp $
#

DISTNAME=	pyncomb-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyncomb/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.site.uottawa.ca/~mraap046
COMMENT=	Python combinatorics library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyncomb-1.0.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
