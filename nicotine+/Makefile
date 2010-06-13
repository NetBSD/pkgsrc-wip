# $NetBSD: Makefile,v 1.15 2010/06/13 22:47:12 thomasklausner Exp $
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
.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	${PYPKGPREFIX}-psyco>=0:../../lang/py-psyco
.endif
DEPENDS+=	${PYPKGPREFIX}-GeoIP>=0:../../net/py-GeoIP

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
