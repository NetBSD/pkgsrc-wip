# $NetBSD: Makefile,v 1.7 2003/11/27 17:16:29 mpasternak Exp $
#

DISTNAME=		fastaudio-0.3
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

BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

EXTRACT_CMD_OPTS.zip=	-aqo

post-extract:
	${MV} ${WRKDIR}/fastaudio/* ${WRKDIR}/portaudio_v18_1

.include "../../audio/libsndfile/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
