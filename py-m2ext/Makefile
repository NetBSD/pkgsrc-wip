# $NetBSD: Makefile,v 1.1 2015/02/20 19:28:47 jihbed Exp $

DISTNAME=	m2ext-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/m2ext/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/abbot/m2ext
COMMENT=	M2Crypto Extensions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-m2crypto>=0.22.3:../../security/py-m2crypto

USE_LANGUAGES=	c

PYDISTUTILSPKG=	yes

BUILD_TARGET=	_m2ext.so

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
