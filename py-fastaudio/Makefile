# $NetBSD: Makefile,v 1.3 2003/11/24 01:01:41 marc Exp $
#

DISTNAME=		fastaudio
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
WRKSRC=			${WRKDIR}/portaudio_v18_1
CATEGORIES=		audio
MASTER_SITES=		http://www.freenet.org.nz/python/pyPortAudio/ \
			http://www.portaudio.com/archives/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			portaudio_v18_1.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.freenet.org.nz/python/pyPortAudio/
COMMENT=		Python bindings for portaudio library

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

EXTRACT_CMD.zip=	${LOCALBASE}/bin/unzip -aqo $${extract_file}
# TODO: should be added, but gives some strange errors on my setup
BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

post-extract:
	${MV} ${WRKDIR}/fastaudio/* ${WRKDIR}/portaudio_v18_1

.include "../../wip/portaudio/buildlink2.mk"
.include "../../audio/libsndfile/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
