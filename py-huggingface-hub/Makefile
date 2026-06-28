# $NetBSD$

DISTNAME=	huggingface_hub-1.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/huggingface-hub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://huggingface.co/docs/huggingface_hub
COMMENT=	The official Python client for the Huggingface Hub
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-click>=8.4.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.10.0:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-fsspec>=2023.5.0:../../sysutils/py-fsspec
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.23.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.9:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.42.1:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-typer>=0.20.0:../../devel/py-typer
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.1.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

SCRIPTS=	hf huggingface-cli tiny-agents

post-install:
.for script in ${SCRIPTS}
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} ${script} ${script}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
