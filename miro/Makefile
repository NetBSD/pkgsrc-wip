# $NetBSD: Makefile,v 1.15 2015/07/13 14:30:33 thomasklausner Exp $

DISTNAME=	miro-3.5.1
PKGREVISION=	2
CATEGORIES=	multimedia net
MASTER_SITES=	http://ftp.osuosl.org/pub/pculture.org/miro/src/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.getmiro.com/
COMMENT=	Miro is a integrated video downloader and player
LICENSE=	gnu-gpl-v2

DEPENDS=	${PYPKGPREFIX}-curl-[0-9]*:../../www/py-curl
DEPENDS+=	${PYPKGPREFIX}-libtorrent-rasterbar-[0-9]*:../../wip/py-libtorrent-rasterbar
DEPENDS+=	${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		linux/setup.py
SUBST_FILES.fix-paths+=		linux/plat/resources.py
SUBST_SED.fix-paths=		-e 's,/usr/share/man/man1,${PKGMANDIR}/man1,g'
SUBST_SED.fix-paths+=		-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.fix-paths+=		-e 's,/usr/X11R6/lib,${X11BASE}/lib,g'

PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	linux
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-pyrex, py-gtk2, py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
