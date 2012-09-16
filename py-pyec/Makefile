# $NetBSD: Makefile,v 1.1 2012/09/16 23:00:46 jihbed Exp $
#

DISTNAME=	PyEC-0.2.5
PKGNAME=	${PYPKGPREFIX}-pyec-0.2.5
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/P/PyEC/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://nn.cs.utexas.edu/?pyec
COMMENT=	Evolutionary computation package
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/PyEC-0.2.5

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
