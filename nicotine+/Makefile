# $NetBSD: Makefile,v 1.10 2007/11/17 08:07:12 netcap Exp $
#

DISTNAME=	nicotine+-1.2.9
CATEGORIES=	net audio x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nicotine-plus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.nicotine-plus.org/
COMMENT=	Client for the SoulSeek, a peer-to-peer network for music

CONFLICTS=	nicotine-[0-9]*
WRKSRC=		${WRKDIR}/${DISTNAME}/
USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	24 23 22
PY_PATCHPLIST=	yes
PYDISTUTILSPKG= yes

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	setup.py
SUBST_SED.man=		-e 's|"share", "man",|"man",|g'

DEPENDS+=	${PYPKGPREFIX}-vorbis>=0:../../audio/py-vorbis

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	${PYPKGPREFIX}-psyco>=0:../../lang/py-psyco
.endif

.include "../../lang/python/extension.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
