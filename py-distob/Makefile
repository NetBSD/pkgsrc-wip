# $NetBSD$

DISTNAME=	distob-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=d/distob/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/mattja/distob/
COMMENT=	Distributed computing made easier, using remote objects
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-ipython>=3.2.1:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.4.1:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-dill>=0.2.4:../../wip/py-dill

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
