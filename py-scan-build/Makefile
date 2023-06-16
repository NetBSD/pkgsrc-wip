# $NetBSD$

DISTNAME=	scan-build-2.0.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scan-build/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rizsotto/scan-build
COMMENT=	Static code analyzer wrapper for Clang
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for file in analyze-build analyze-c++ analyze-cc intercept-build intercept-c++ intercept-cc scan-build
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${file} ${file}-${PYVERSSUFFIX}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
