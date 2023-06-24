# $NetBSD$

DISTNAME=	polars-0.15.14
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/polars/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pola.rs/
COMMENT=	Lightning-fast DataFrame library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../devel/py-maturin

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=		27

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} maturin-${PYVERSSUFFIX} pep517 \
		build-wheel -i ${PREFIX}/bin/python${PYVERSSUFFIX} --compatibility off \
		--offline

WHEELFILE=	${WRKSRC}/target/wheels/*.whl

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
