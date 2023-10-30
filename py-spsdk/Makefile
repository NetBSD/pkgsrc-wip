# $NetBSD$

DISTNAME=	spsdk-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spsdk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NXPmicro/spsdk
COMMENT=	Open Source Secure Provisioning SDK for NXP MCU/MPU
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1crypto>=1.2:../../security/py-asn1crypto
DEPENDS+=	${PYPKGPREFIX}-astunparse>=1.6:../../devel/py-astunparse
DEPENDS+=	# TODO: bincopy>=17.14.5
DEPENDS+=	${PYPKGPREFIX}-bitstring>=3.1:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-click-option-group>=0.3.0:../../wip/py-click-option-group
DEPENDS+=	# TODO: click-command-tree>=0
DEPENDS+=	${PYPKGPREFIX}-click>=7.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6:../../comms/py-colorama
DEPENDS+=	# TODO: commentjson>=0.9
DEPENDS+=	${PYPKGPREFIX}-crcmod>=0:../../security/py-crcmod
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.4.4:../../security/py-cryptography
DEPENDS+=	# TODO: deepmerge>=0
DEPENDS+=	${PYPKGPREFIX}-fastjsonschema>=2.15.1:../../textproc/py-fastjsonschema
DEPENDS+=	# TODO: hexdump<3.4>=0
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	# TODO: libusbsio>=2.1.11
DEPENDS+=	# TODO: oscrypto<1.4>=0
DEPENDS+=	# TODO: pylink-square>=1.0
DEPENDS+=	# TODO: pyocd-pemicro>=1.1.5
DEPENDS+=	# TODO: pyocd>=0.35.1
DEPENDS+=	# TODO: pypemicro>=0.1.11
DEPENDS+=	${PYPKGPREFIX}-serial>=3.1:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.17:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	# TODO: sly<0.6>=0
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
