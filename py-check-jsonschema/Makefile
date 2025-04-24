# $NetBSD: Makefile,v 1.10 2022/01/04 20:54:32 wiz Exp $

DISTNAME=	check-jsonschema-0.28.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/check-jsonschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-jsonschema/check-jsonschema
COMMENT=	CLI for jsonschema validation
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click>=8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.18.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-regress>=0.4.0:../../wip/py-regress
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.18.5:../../devel/py-ruamel-yaml

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0:../../textproc/py-tomli
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} check-jsonschema check-jsonschema${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
