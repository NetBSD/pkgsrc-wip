# $NetBSD$

DISTNAME=	python-u2flib-server-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-u2flib-server/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/Yubico/python-u2flib-server/
COMMENT=	Python based U2F server library
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.2.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six

.include "../../wip/python/distutils.mk"
#.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
