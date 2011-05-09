# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:05:17 jihbed Exp $
#

DISTNAME=	pyutilib.misc-4.3
PKGNAME=	${PYPKGPREFIX}-utilib_misc-4.3
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutilib.misc/


MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://software.sandia.gov/svn/public/pyutilib/pyutilib.misc/
COMMENT=	Miscellaneous PyUtilib utilities
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-utilib_common>=3.0.4:../../wip/py-utilib_common

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyutilib.misc-4.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
