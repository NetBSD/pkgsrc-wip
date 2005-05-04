# $NetBSD: Makefile,v 1.2 2005/05/04 01:13:21 jeremy-c-reed Exp $
#

PKGREVISION=		1
COMMENT=		Flexible printing subsystem

CONFIGURE_ENV+=		GLIB_CONFIG=NO # make sure xpdq is not built

USE_PKGINSTALL=		yes
CONF_FILES=		${PREFIX}/share/pdq/printrc.example ${PKG_SYSCONFDIR}/printrc

.include "../../mk/bsd.prefs.mk"

.if ${LOCALBASE} == "/usr" || !exists(/usr/bin/file)
DEPENDS+=		file-[0-9]*:../../sysutils/file
.endif

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
