# $NetBSD$

DISTNAME=	jitcxde_common-1.5.2
PKGNAME=	${PYPKGPREFIX}-jitcxde-common-1.5.2
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/92/12/4029d5ec36e8dbc6bae6ff0d99195a3c28f189a4e6c6105421585c00370d/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/neurophysik/jitcxde_common
COMMENT=	Common code for JiTC*DE
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
#DEPENDS+=	${PYPKGPREFIX}-symengine>=0.3.1.dev0:../../category/py-symengine
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
