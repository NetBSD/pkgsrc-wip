# $NetBSD$

DISTNAME=	jupyter_server-1.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/jupyter_server/
COMMENT=	Backend for Jupyter web applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-anyio>=3.1.0:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi>0:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-jinja2>0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.12:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.7.0:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-nbconvert>=6.4.4:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.2.0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-zmq>=17.0.0:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-Send2Trash>0:../../sysutils/py-Send2Trash
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.1:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-websocket-client>0:../../www/py-websocket-client

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

post-install:
.for name in server
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-${name} jupyter-${name}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
