# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:11 thomasklausner Exp $
#

DISTNAME=	miro-3.0.1
PKGREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	http://ftp.osuosl.org/pub/pculture.org/miro/src/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.getmiro.com/
COMMENT=	Miro is a integrated video downloader and player

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=	pkg-config

DEPENDS=	${PYPKGPREFIX}-pyrex>=0.9.6.4:../../lang/py-pyrex
DEPENDS+=	${PYPKGPREFIX}-libtorrent-rasterbar>=0.15.0:../../wip/py-libtorrent-rasterbar

PYTHON_VERSIONS_ACCEPTED=	26 25
PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	platform/gtk-x11
REPLACE_PYTHON=	${WRKSRC}/platform/gtk-x11/miro.real

SUBST_CLASSES+=		xpcom
SUBST_STAGE.xpcom=	pre-configure
SUBST_MESSAGE.xpcom=	This should be done by pkg-config.
SUBST_FILES.xpcom=	platform/gtk-x11/setup.py
SUBST_SED.xpcom=	-e 's,XPCOM_RUNTIME_PATH = None,XPCOM_RUNTIME_PATH = "${PREFIX}/lib/xulrunner",g'

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		platform/gtk-x11/setup.py
SUBST_FILES.fix-paths+=		platform/gtk-x11/plat/resources.py
SUBST_SED.fix-paths=		-e 's,/usr/share/man/man1,${PKGMANDIR}/man1,g'
SUBST_SED.fix-paths+=		-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.fix-paths+=		-e 's,/usr/X11R6/lib,${X11BASE}/lib,g'

.include "../../lang/python/application.mk"
.include "../../devel/xulrunner/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
#.include "../../devel/boost-python/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
