# $NetBSD: Makefile,v 1.9 2004/03/20 21:59:31 mpasternak Exp $
#

DISTNAME=		fastaudio
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}-0.3
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

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
MAKE_ENV+=		PTHREAD_LDFLAGS="${PTHREAD_LDFLAGS}"

EXTRACT_CMD_OPTS.zip=	-aqo

post-extract:
	${MV} ${WRKDIR}/fastaudio/* ${WRKDIR}/portaudio_v18_1

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
