# $NetBSD: Makefile,v 1.4 2006/05/05 22:30:14 jeremy-c-reed Exp $
#

PKGREVISION=		2
COMMENT=		Flexible printing subsystem

CONFIGURE_ENV+=		GLIB_CONFIG=NO # make sure xpdq is not built

CONF_FILES=		${PREFIX}/share/pdq/printrc.example ${PKG_SYSCONFDIR}/printrc
LICENSE=		gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

.if ${PREFIX} == "/usr" || !exists(/usr/bin/file)
DEPENDS+=		file-[0-9]*:../../sysutils/file
.endif

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
