# $NetBSD: Makefile,v 1.3 2012/04/08 19:09:43 thomasklausner Exp $
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
