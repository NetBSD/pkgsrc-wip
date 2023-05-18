# $NetBSD: Makefile,v 1.4 2023/05/18 09:56:50 nikita Exp $

DISTNAME=	libusb1-1.9.3
PKGNAME=	py27-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libusb1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vpelletier/python-libusb1
COMMENT=	Python ctype-based wrapper around libusb1
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

# dropped support for < 3.4 in version 2.0
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
