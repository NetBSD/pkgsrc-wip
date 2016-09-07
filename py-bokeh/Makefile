# $NetBSD$

DISTNAME=	bokeh-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bokeh/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/bokeh/bokeh
COMMENT=	Statistical and novel interactive HTML plots for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-futures>=3.0.5:../../devel/py-futures
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.1:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.0.1:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-itsdangerous-[0-9]*:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.2.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=0.23:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

DEPENDS+=	${PYPKGPREFIX}-pystache>=0.5.4:../../wip/py-stache
DEPENDS+=	${PYPKGPREFIX}-flask>=0.10.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

WRKSRC=		${WRKDIR}/bokeh-0.12.2

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
