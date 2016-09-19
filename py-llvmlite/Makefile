# $NetBSD$

DISTNAME=	llvmlite-0.14.0.dev
GITHUB_PROJECT=	llvmlite
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=numba/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvmlite.pydata.org/
COMMENT=	Lightweight LLVM python binding for JIT compilers
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c++

DEPENDS+=	${PYPKGPREFIX}-enum-[0-9]*:../../devel/py-enum
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

EGG_NAME=	llvmlite-0.13.0

.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
