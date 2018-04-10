# $NetBSD$

DISTNAME=	absl-py-0.1.13
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     devel python
MASTER_SITES=   ${MASTER_SITE_PYPI:=a/absl-py/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/abseil/abseil-py
COMMENT=	Abseil Python Common Libraries
LICENSE=	apache-2.0

DEPENDS+=       ${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

.include "../../lang/python/egg.mk"
WRKSRC=		${WRKDIR}/absl-py-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
