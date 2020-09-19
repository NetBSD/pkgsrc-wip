# $NetBSD$

DISTNAME=	qtt-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/f6/97/ffe957c0c3e39f702cfd64650f9513bf6255c0480ab3b05410bcc6faac0e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://qutech.nl/
COMMENT=	Python-based framework for analysis and tuning of quantum dots
LICENSE=	mit

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
