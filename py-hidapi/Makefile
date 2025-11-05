# $NetBSD$

NAME=		hidapi
VERSION=	0.14.0
DISTNAME=	${NAME}-${VERSION}.post4
PKGNAME=	${PYPKGPREFIX}-${NAME}-${VERSION}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hidapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trezor/cython-hidapi
COMMENT=	Cython interface to the hidapi
LICENSE=	modified-bsd OR gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	HIDAPI_SYSTEM_HIDAPI=1
MAKE_ENV+=	HIDAPI_WITH_LIBUSB=1

.include "../../lang/python/wheel.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../comms/libhidapi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
