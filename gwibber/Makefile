# $NetBSD: Makefile,v 1.2 2010/11/25 11:42:23 ryo-on Exp $
#

DISTNAME=	gwibber_2.91.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/g/gwibber/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://gwibber.com/
COMMENT=	Open source microblogging client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	26 25
PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/gwibber-2.91.0
USE_LANGUAGES=	# none
USE_TOOLS+=	intltool

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
DEPENDS+=	${PYPKGPREFIX}-mako>=0.2.2:../../wip/py-mako
DEPENDS+=	${PYPKGPREFIX}-curl-[0-9]*:../../www/py-curl
DEPENDS+=	${PYPKGPREFIX}-gnome2-desktop-[0-9]*:../../x11/py-gnome2-desktop
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
#DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../wip/py-keyring
DEPENDS+=	gnome-keyring-[0-9]*:../../security/gnome-keyring

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	setup.cfg
SUBST_SED.prefix=	-e 's,/usr,${PREFIX},'

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
