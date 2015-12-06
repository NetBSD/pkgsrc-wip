# $NetBSD: Makefile,v 1.2 2015/06/07 14:27:04 thomasklausner Exp $

DISTNAME=	sync-server-dependencies-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://docs.services.mozilla.com/howtos/run-sync.html
COMMENT=	Meta Package for Firefox Sync Server's dependencies
LICENSE=	public-domain

USE_TOOLS+=	gmake:run

DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
DEPENDS+=	mercurial-[0-9]*:../../devel/mercurial
DEPENDS+=	sqlite3-[0-9]*:../../databases/sqlite3

META_PACKAGE=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # only supports 2.7

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
