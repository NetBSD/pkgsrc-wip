# $NetBSD: Makefile,v 1.3 2006/03/14 01:28:08 jlamwww Exp $
#

PKGREVISION=		1
COMMENT=		Flexible printing subsystem

CONFIGURE_ENV+=		GLIB_CONFIG=NO # make sure xpdq is not built

CONF_FILES=		${PREFIX}/share/pdq/printrc.example ${PKG_SYSCONFDIR}/printrc

.include "../../mk/bsd.prefs.mk"

.if ${LOCALBASE} == "/usr" || !exists(/usr/bin/file)
DEPENDS+=		file-[0-9]*:../../sysutils/file
.endif

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
