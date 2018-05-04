# $NetBSD$

DISTNAME=	python-u2flib-server-5.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-u2flib-server/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/Yubico/python-u2flib-server/
COMMENT=	Python based U2F server library
#LICENSE=	# TODO: (see mk/license.mk)


DEPENDS+=       ${PYPKGPREFIX}-cryptography>=1.2.0:../../security/py-cryptography
DEPENDS+=       ${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six

.include "../../lang/python/distutils.mk"

.if ${PYVERSSUFFIX} == "3.4"
DEPENDS+=       ${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

.include "../../mk/bsd.prefs.mk"

#.include "../../lang/python/egg.mk"
#.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
