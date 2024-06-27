# $NetBSD$

DISTNAME=	anywidget-0.9.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anywidget/}

MAINTAINER=	matthewd@fastmail.us # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/anywidget/
COMMENT=	Custom jupyter widgets made easy
LICENSE=	mit

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE= 27 38

DEPENDS+=	${PYPKGPREFIX}-ipywidgets>=7.0.0:../../www/py-ipywidgets
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.2:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-psygnal>=0.11.1:../../wip/py-psygnal
DEPENDS+=	${PYPKGPREFIX}-hatch-jupyter-builder>=0.9.1:../../devel/py-hatch-jupyter-builder

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.3.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-watchfiles>=0.22.0:../../misc/py-watchfiles

CONF_FILES=	${PREFIX}/share/examples/jupyter/nbconfig/notebook.d/anywidget.json \
			${PKG_SYSCONFDIR}/jupyter/nbconfig/notebook.d/anywidget.json

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
