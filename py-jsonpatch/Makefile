# $NetBSD$

DISTNAME=	jsonpatch-1.32
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stefankoegl/python-json-patch
COMMENT=	Apply JSON Patches according to RFC 6902
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jsonpointer>=0.19:../../wip/py-jsonpointer

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
