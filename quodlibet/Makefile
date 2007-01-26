# $NetBSD: Makefile,v 1.5 2007/01/26 00:46:26 thomasklausner Exp $
#

DISTNAME=		quodlibet-0.24
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://www.sacredchao.net/~piman/software/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.sacredchao.net/quodlibet/wiki
COMMENT=		Finally a good alternative to iTunes

DEPENDS+=		${PYPKGPREFIX}-mutagen>=1.8:../../audio/py-mutagen
DEPENDS+=		gst-python>=0.10.0:../../multimedia/py-gstreamer0.10
DEPENDS+=		gst-plugins0.10-mad>=0.10.0:../../audio/gst-plugins0.10-mad
DEPENDS+=		gst-plugins0.10-vorbis>=0.10.0:../../audio/gst-plugins0.10-vorbis
DEPENDS+=		gst-plugins0.10-ogg>=0.10.0:../../multimedia/gst-plugins0.10-ogg

PYTHON_VERSIONS_ACCEPTED=	24 25
PYTHON_PATCH_SCRIPTS=	*.py */*.py
USE_DIRS+=		xdg-1.4
USE_TOOLS+=		gmake intltool
USE_PKGLOCALEDIR=	yes
BUILD_TARGET=		_trayicon.so _mmkeys.so

.include "../../lang/python/application.mk"
# complains about importing missing dbus during startup, but
# works fine without it. With py-dbus installed however, it
# fails loading hal and exits.
#.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
