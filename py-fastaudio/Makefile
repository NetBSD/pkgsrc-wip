# $NetBSD: Makefile,v 1.11 2005/07/27 16:28:20 thomasklausner Exp $
#

DISTNAME=		fastaudio
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}-0.3
WRKSRC=			${WRKDIR}/portaudio_v18_1
CATEGORIES=		audio
MASTER_SITES=		http://www.freenet.org.nz/python/pyPortAudio/ \
			http://www.portaudio.com/archives/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			portaudio_v18_1.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freenet.org.nz/python/pyPortAudio/
COMMENT=		Python bindings for portaudio library

BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

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
