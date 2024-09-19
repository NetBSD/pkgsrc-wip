# $NetBSD$

DISTNAME=	python3-keyczar-0.71rc0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python3-//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python3-keyczar/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.keyczar.org/
COMMENT=	Toolkit for safe and simple cryptography
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6.1:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
