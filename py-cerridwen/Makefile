# $NetBSD: Makefile,v 1.1 2014/06/28 20:20:37 jihbed Exp $

DISTNAME=	cerridwen-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	https://pypi.python.org/packages/source/c/cerridwen/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cerridwen.viridian-project.de/
COMMENT=	Accurate solar system data for everyone
LICENSE=	mit

WRKSRC=		${WRKDIR}/cerridwen-1.3.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-astropy>=0.3.1:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-pyswisseph-[0-9]*:../../wip/py-pyswisseph
.include "../../mk/bsd.pkg.mk"
