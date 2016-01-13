# $NetBSD$

DISTNAME=	${PYPKGPREFIX}-pithos-1.1.2
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_GITHUB:=pithos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pithos.github.io/
COMMENT=	Native grapical client for Pandora
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-last-[0-9]*:../../audio/py-last
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	gst-plugins1-bad-[0-9]*:../../multimedia/gst-plugins1-bad
DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=	gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
DEPENDS+=	gnome-icon-theme-symbolic-[0-9]*:../../graphics/gnome-icon-theme-symbolic
#DEPENDS+=	${PYPKGPREFIX}-notify-[0-9]*:../../sysutils/py-notify

# https://github.com/pithos/pithos/wiki/Installing-from-Source
# missing, perhaps:
# python3-gi-cairo \
# gir1.2-gstreamer-1.0 gir1.2-gst-plugins-base-1.0
# gir1.2-secret-1
# gir1.2-appindicator3-0.1 gir1.2-notify-0.7 gir1.2-keybinder-3.0

USE_LANGUAGES=	# none
USE_TOOLS+=	intltool
PYTHON_VERSIONS_INCOMPATIBLE=	27 33
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

SUBST_CLASSES+=		prefix
SUBST_SED.prefix+=	-e "s,/usr,${PREFIX},g"
SUBST_FILES.prefix+=	setup.py
SUBST_MESSAGE.prefix=	Fix installation prefix.
SUBST_STAGE.prefix=	pre-configure

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pithos ${DESTDIR}${PREFIX}/bin/pithos-${PYVERSSUFFIX}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
