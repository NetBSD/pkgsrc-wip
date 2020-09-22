# $NetBSD$

DISTNAME=	etesync-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://files.pythonhosted.org/packages/0b/e1/4e096e782818af4a7d5210f3072d1206b4da3a50d18f30b8b6811118a497/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/etesync/pyetesync
COMMENT=	Python client library for EteSync
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-asn1crypto>=0.22:../../security/py-asn1crypto
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.10:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.9.2:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-furl>=0.5:../../www/py-furl
DEPENDS+=	${PYPKGPREFIX}-idna>=2.5:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-orderedmultidict>=0.7:../../databases/py-orderedmultidict
DEPENDS+=	${PYPKGPREFIX}-packaging>=16.8:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-peewee>=3.7.0:../../databases/py-peewee
DEPENDS+=	${PYPKGPREFIX}-py>=1.4:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.2:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pytz>=2019.1:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.21:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-vobject>=0.9:../../textproc/py-vobject

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
