# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:00:19 jihbed Exp $
#

DISTNAME=	pyutilib.excel-3.0.4
PKGNAME=	${PYPKGPREFIX}-utilib_excel-3.0.4
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutilib.excel/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://software.sandia.gov/svn/public/pyutilib/pyutilib.excel
COMMENT=	PyUtilib utilities that use Excel spreadsheets
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-utilib_common>=3.0.4:../../wip/py-utilib_common
#DEPENDS+=	${PYPKGPREFIX}-utilib_th>=3.0.4:../../wip/py-utilib_th

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyutilib.excel-3.0.4
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
