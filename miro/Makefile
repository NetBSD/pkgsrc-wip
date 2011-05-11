# $NetBSD: Makefile,v 1.5 2011/05/11 09:22:53 ryo-on Exp $
#

DISTNAME=	miro-3.5.1
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

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		linux/setup.py
SUBST_FILES.fix-paths+=		linux/plat/resources.py
SUBST_SED.fix-paths=		-e 's,/usr/share/man/man1,${PKGMANDIR}/man1,g'
SUBST_SED.fix-paths+=		-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.fix-paths+=		-e 's,/usr/X11R6/lib,${X11BASE}/lib,g'

DEPENDS=	${PYPKGPREFIX}-curl-[0-9]*:../../www/py-curl
DEPENDS+=	${PYPKGPREFIX}-libtorrent-rasterbar-[0-9]*:../../www/py-libtorrent-rasterbar

PYTHON_VERSIONS_ACCEPTED=	27 26 25
PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	linux

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
