# $NetBSD$

DISTNAME=	pynitrokey-0.4.43
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynitrokey/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/Nitrokey/pynitrokey
COMMENT=	Python library for Nitrokey devices
LICENSE=	apache-2.0 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit>=3.8.0:../../devel/py-flit
DEPENDS+=	libnitrokey-[0-9]*:../../security/libnitrokey
DEPENDS+=	${PYPKGPREFIX}-certifi>=14.5.14:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-click>=8.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-aliases-[0-9]*:../../devel/py-click-aliases
DEPENDS+=	${PYPKGPREFIX}-cryptography>=41.0.4:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-ecdsa-[0-9]*:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-fido2>=1.1.2:../../security/py-fido2
DEPENDS+=	${PYPKGPREFIX}-intelhex-[0-9]*:../../devel/py-intelhex
DEPENDS+=	${PYPKGPREFIX}-nethsm>=1.0.0:../../wip/py-nethsm
DEPENDS+=	${PYPKGPREFIX}-nkdfu-[0-9]*:../../sysutils/py-nkdfu
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.17.3:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-semver-[0-9]*:../../wip/py-semver
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-spsdk>=1.11.0:../../wip/py-spsdk
DEPENDS+=	${PYPKGPREFIX}-tlv8-[0-9]*:../../devel/py-tlv8
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-usb-[0-9]*:../../devel/py-usb

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

REPLACE_PYTHON+=	pynitrokey/start/usb_strings.py
REPLACE_PYTHON+=	pynitrokey/start/upgrade_by_passwd.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
        ${MV} nitropy nitropy-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
