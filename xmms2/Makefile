# $NetBSD: Makefile,v 1.9 2006/03/09 21:02:16 jlamwww Exp $
#

DISTNAME=	xmms2-0.2DrAlban
PKGNAME=	xmms2-0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmms2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xmms2.xmms.org/
COMMENT=	Audio player featuring a client-server model

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
.include "../../audio/libmad/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons \
		EXCLUDE="${EXCLUDES}"

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons install

.include "../../mk/bsd.pkg.mk"
