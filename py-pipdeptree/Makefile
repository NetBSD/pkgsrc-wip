# $NetBSD$

DISTNAME=	pipdeptree-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pipdeptree/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/naiquevin/pipdeptree
COMMENT=	Displaying the installed python packages in form of a dependency tree
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pipdeptree pipdeptree-${PYVERSSUFFIX}

DEPENDS+=       ${PYPKGPREFIX}-pip>=6.0.0:../../devel/py-pip

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
