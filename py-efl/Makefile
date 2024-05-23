# $NetBSD$

VERSION=	1.26.1
DISTNAME=	python-efl-${VERSION}
PKGNAME=	${PYPKGPREFIX}-efl-${VERSION}
CATEGORIES=	python
MASTER_SITES=	https://download.enlightenment.org/rel/bindings/python/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://download.enlightenment.org/rel/bindings/python/
COMMENT=	Python bindings for the enlightenment foundation libraries
LICENSE=	gnu-gpl-v3
PYTHON_VERSIONS_INCOMPATIBLE=	27


USE_TOOLS=	pkg-config

LUA_VERSIONS_ACCEPTED=	52 51
.include "../../lang/lua/luaversion.mk"

# Does not work with wheel.mk yet
.include "../../lang/python/egg.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../wip/efl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
