# $NetBSD: Makefile,v 1.1.1.1 2010/05/12 16:05:21 jihbed Exp $
#

DISTNAME=	desktopcouch-0.6.4
CATEGORIES=	databases python
MASTER_SITES=	http://launchpad.net/desktopcouch/trunk/0.6.4/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/desktopcouch
COMMENT=	Desktop couchDB
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-dbus>=0.83.0:../../sysutils/py-dbus
#DEPENDS+=	${PYPKGPREFIX}-couchdb>=0.6:../../wip/py-couchdb
#DEPENDS+=	${PYPKGPREFIX}-distutils-extra>=2.18:../../wip/py-distutils-extra

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	intltool
USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,share/man/man1,${PREFIX}/man/man1,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
