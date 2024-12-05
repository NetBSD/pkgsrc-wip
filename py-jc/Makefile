# $NetBSD$

DISTNAME=	jc-1.25.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kellyjonbrazil/jc
COMMENT=	Convert output of popular command-line tools and file-types to JSON
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.12.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.3.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.0:../../devel/py-ruamel-yaml

USE_LANGUAGES=	# none

# test data not included
# https://github.com/kellyjonbrazil/jc/issues/620

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} jc jc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
