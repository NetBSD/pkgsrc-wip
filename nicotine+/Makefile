# $NetBSD: Makefile,v 1.17 2012/10/12 20:32:05 asau Exp $
#

DISTNAME=	nicotine+-1.2.9
PKGREVISION=	1
CATEGORIES=	net audio x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nicotine-plus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.nicotine-plus.org/
COMMENT=	Client for the SoulSeek, a peer-to-peer network for music

CONFLICTS=	nicotine-[0-9]*
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-vorbis>=0:../../audio/py-vorbis
DEPENDS+=	${PYPKGPREFIX}-GeoIP>=0:../../net/py-GeoIP

PKG_DESTDIR_SUPPORT=	none

PY_PATCHPLIST=	yes
PYDISTUTILSPKG= yes
REPLACE_PYTHON=	pynicotine/gtkgui/glade2py.py

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	setup.py
SUBST_SED.man=		-e 's|"share", "man",|"man",|g'

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
