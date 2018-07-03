# $NetBSD: Makefile,v 1.18 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=		fastaudio
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}-0.3
WRKSRC=			${WRKDIR}/portaudio_v18_1
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.freenet.org.nz/python/pyPortAudio/ \
			http://www.portaudio.com/archives/
DISTFILES=		${DEFAULT_DISTFILES} portaudio_v18_1.zip
LICENSE=		mit

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freenet.org.nz/python/pyPortAudio/
COMMENT=		Python bindings for portaudio library

BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-pyrex

MAKE_ENV+=		PTHREAD_LDFLAGS=${PTHREAD_LDFLAGS:Q}

EXTRACT_CMD_OPTS.zip=	-aqo

post-extract:
	${MV} ${WRKDIR}/fastaudio/* ${WRKDIR}/portaudio_v18_1

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
