# $NetBSD: Makefile,v 1.1.1.1 2005/09/12 21:19:17 leonardschmidt Exp $
#

DISTNAME=	xmms2-0.1DR2.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmms2/}

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://xmms2.xmms.org/
COMMENT=	Audio player using a client-server model

NO_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

MANCOMPRESSED=		yes

BUILD_DEPENDS+=		scons>=0.96.1nb1:../../devel/scons

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons install

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
