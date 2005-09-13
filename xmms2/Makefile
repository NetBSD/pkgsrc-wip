# $NetBSD: Makefile,v 1.3 2005/09/13 21:18:09 leonardschmidt Exp $
#

DISTNAME=	xmms2-0.1DR2.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmms2/}

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://xmms2.xmms.org/
COMMENT=	Audio player using a client-server model

BUILD_DEPENDS+=		scons>=0.96.1nb1:../../devel/scons

NO_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
MANCOMPRESSED=		yes

PKGCONFIG_OVERRIDE=	xmms2-client-ecore.pc
PKGCONFIG_OVERRIDE+=	xmms2-client-glib.pc
PKGCONFIG_OVERRIDE+=	xmms2-client.pc
PKGCONFIG_OVERRIDE+=	xmms2-plugin.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "options.mk"

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons EXCLUDE="${EXCLUDE}"

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons install

.include "../../audio/libmad/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
