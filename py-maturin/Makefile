# $NetBSD: Makefile,v 1.4 2020/04/18 10:52:10 js Exp $

DISTNAME=	maturin-0.12.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maturin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyO3/maturin
COMMENT=	Build and publish crates with pyo3, rust-cpython and cffi bindings
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli

SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	pre-build
SUBST_MESSAGE.fix-version=	Adding version to pyproject.toml
SUBST_FILES.fix-version=	pyproject.toml
SUBST_SED.fix-version=		-e 's|PKGSRC_VERSION|"'${PKGVERSION_NOREV}'"|'

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} maturin maturin-${PYVERSSUFFIX}

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
