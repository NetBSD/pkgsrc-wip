# $NetBSD$

DISTNAME=	pyramid-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyramid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://trypyramid.com/
COMMENT=	Pyramid Web Framework, a Pylons project
LICENSE=	original-bsd AND zpl-2.1 AND cc-by-nc-sa-v3.0-license AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-hupper>=1.5:../../sysutils/py-hupper
DEPENDS+=	${PYPKGPREFIX}-plaster>=0:../../devel/py-plaster
DEPENDS+=	${PYPKGPREFIX}-plaster_pastedeploy>=0:../../www/py-plaster_pastedeploy
DEPENDS+=	${PYPKGPREFIX}-translationstring>=0.4:../../wip/py-translationstring
DEPENDS+=	${PYPKGPREFIX}-venusian>=1.0:../../wip/py-venusian
DEPENDS+=	${PYPKGPREFIX}-WebOb>=1.8.3:../../www/py-WebOb
DEPENDS+=	${PYPKGPREFIX}-zope.deprecation>=3.5.0:../../devel/py-zope.deprecation
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=3.8.0:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest>=1.3.1:../../www/py-WebTest
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.component>=4.0:../../devel/py-zope.component

USE_LANGUAGES=		# none

post-install:
.for file in pdistreport prequest proutes pserve pshell ptweens pviews
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${file} ${file}-${PYVERSSUFFIX}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
