# $NetBSD: Makefile,v 1.5 2003/11/25 22:18:32 mpasternak Exp $
#

DISTNAME=		fastaudio
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}-0.1
WRKSRC=			${WRKDIR}/portaudio_v18_1
CATEGORIES=		audio
MASTER_SITES=		http://www.freenet.org.nz/python/pyPortAudio/ \
			http://www.portaudio.com/archives/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			portaudio_v18_1.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.freenet.org.nz/python/pyPortAudio/
COMMENT=		Python bindings for portaudio library

BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

EXTRACT_CMD.zip=	${LOCALBASE}/bin/unzip -aqo $${extract_file}

post-extract:
	${MV} ${WRKDIR}/fastaudio/* ${WRKDIR}/portaudio_v18_1

.include "../../wip/portaudio/buildlink2.mk"
.include "../../audio/libsndfile/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
