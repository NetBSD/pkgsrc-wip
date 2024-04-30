# $NetBSD$

DISTNAME=	pipdeptree-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pipdeptree/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/naiquevin/pipdeptree
COMMENT=	Displaying the installed python packages in form of a dependency tree
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pipdeptree pipdeptree-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
