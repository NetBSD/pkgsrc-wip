# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:47 thomasklausner Exp $
#

PKGNAME=	${DISTNAME:S/^M/m/}
DISTNAME=	Manifold-0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://pypi.python.org/packages/source/M/Manifold/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://code.google.com/p/manifold/
COMMENT=	SMF service manifest creation tool
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-genshi-[0-9]*:../../www/py-genshi

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PLIST_SUBST+=	DISTNAME=${DISTNAME}
PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
