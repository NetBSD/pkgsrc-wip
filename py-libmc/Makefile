# $NetBSD: Makefile,v 1.2 2010/06/09 11:35:53 fhajny Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
DISTNAME=	pylibmc-1.1.1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pylibmc/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://pypi.python.org/pypi/pylibmc
COMMENT=	Python wrapper around libmemcached from TangentOrg
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_ACCEPTED=	26 25

.include "../../wip/libmemcached/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
