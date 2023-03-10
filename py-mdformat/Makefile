# $NetBSD$

DISTNAME=	mdformat-0.7.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mdformat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mdformat.rtfd.io/
COMMENT=	CommonMark compliant Markdown formatter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=1.0.0:../../textproc/py-markdown-it-py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} < 37
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions
.endif

.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6.0:../../devel/py-importlib-metadata
.endif

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/mdformat ${DESTDIR}${PREFIX}/bin/mdformat${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
