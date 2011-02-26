# $NetBSD: Makefile,v 1.6 2011/02/26 10:04:06 ryo-on Exp $
#

DISTNAME=	gwibber-2.91.90
CATEGORIES=	net
MASTER_SITES=	http://launchpad.net/gwibber/trunk/2.91.90/+download/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://gwibber.com/
COMMENT=	Open source microblogging client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	27 26 25
PYDISTUTILSPKG=	yes

USE_LANGUAGES=	# none
USE_TOOLS+=	intltool msgfmt

DEPENDS+=	${PYPKGPREFIX}-dbus>=0.80.2:../../sysutils/py-dbus
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.10.4:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-gnome2>=2.18.0:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1.6:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-notify>=0.1.1:../../sysutils/py-notify
DEPENDS+=	${PYPKGPREFIX}-webkitgtk>=1.0.1:../../wip/py-webkit
DEPENDS+=	${PYPKGPREFIX}-simplejson>=1.9.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-mx-base>=3.0.0:../../wip/py-mx-base
DEPENDS+=	${PYPKGPREFIX}-distutils-extra-[0-9]*:../../wip/py-distutils-extra
DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-xdg>=0.15:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-mako>=0.2.2:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-curl-[0-9]*:../../www/py-curl
DEPENDS+=	${PYPKGPREFIX}-gnome2-desktop-[0-9]*:../../x11/py-gnome2-desktop
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
#DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../wip/py-keyring
DEPENDS+=	${PYPKGPREFIX}-oauth-[0-9]*:../../security/py-oauth
DEPENDS+=	${PYPKGPREFIX}-gnome2-extras-[0-9]*:../../x11/py-gnome2-extras

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	setup.cfg
SUBST_FILES.prefix+=	com.Gwibber*
SUBST_SED.prefix=	-e 's,/usr,${PREFIX},'

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
