# $NetBSD$

DISTNAME=	pynitrokey-0.4.36
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S,py,,}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynitrokey/}
#MASTER_SITES=	${MASTER_SITE_GITHUB:=Nitrokey/}
#GITHUB_PROJECT=	pynitrokey
#GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pynitrokey/
COMMENT=	Python library for Nitrokey devices
LICENSE=	apache-2.0 AND mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-flit>=3.8.0:../../devel/py-flit
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-frozendict-[0-9]*:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-intelhex-[0-9]*:../../devel/py-intelhex
DEPENDS+=	${PYPKGPREFIX}-protobuf-[0-9]*:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-scard-[0-9]*:../../devel/py-scard
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
#DEPENDS+=	${PYPKGPREFIX}-libusb1-[0-9]*:../../devel/py-libusb1  # TODO: package this
#DEPENDS+=	${PYPKGPREFIX}-nkdfu-[0-9]*:../../devel/py-nkdfu
#DEPENDS+=	${PYPKGPREFIX}-spsdk-[0-9]*:../../devel/py-spsdk
#DEPENDS+=	${PYPKGPREFIX}-tlv8-[0-9]*:../../devel/py-tlv8
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-ecdsa-[0-9]*:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-fido2-[0-9]*:../../security/py-fido2
#DEPENDS+=	libnitrokey-[0-9]*:../../security/libnitrokey
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

#post-install:
#	cd ${DESTDIR}${PREFIX}/bin && \
#        ${MV} pip-audit pip-audit-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
