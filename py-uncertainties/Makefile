# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:52 thomasklausner Exp $
#

DISTNAME=	uncertainties-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics python
MASTER_SITES=	http://pypi.python.org/packages/source/u/uncertainties/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/uncertainties/
COMMENT=	Support for physical quantities with units, based on numpy
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/uncertainties-1.7.1

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
