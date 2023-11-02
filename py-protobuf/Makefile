# $NetBSD: Makefile,v 1.65 2023/03/29 09:34:09 wiz Exp $

DISTNAME=	protobuf-4.24.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/protobuf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers/
COMMENT=	Python bindings for protobuf
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES+=	c c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	PROTOC=${PREFIX}/bin/protoc

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
