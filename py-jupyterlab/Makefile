# $NetBSD$

DISTNAME=	jupyterlab-3.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/jupyterlab/
COMMENT=	Next-generation user interface for Project Jupyter
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ipython>=8.4.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.6.1:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyterlab_server>=2.10:../../wip/py-jupyterlab_server
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.16:../../wip/py-jupyter_server
DEPENDS+=	${PYPKGPREFIX}-nbclassic>0:../../wip/py-nbclassic
DEPENDS+=	${PYPKGPREFIX}-notebook>0:../../www/py-notebook
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.1:../../textproc/py-jinja2
DEPENDS+=	npm>0:../../lang/npm

PYTHON_VERSIONS_INCOMPATIBLE=	27

MESSAGE_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jlpm jlpm-${PYVERSSUFFIX} || ${TRUE}
.for name in lab labextension labhub
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-${name} jupyter-${name}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
