# $NetBSD: Makefile,v 1.12 2012/11/13 20:09:29 othyro Exp $
#

DISTNAME=	emelfm2-0.1.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://emelfm2.net/rel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://emelfm2.net/
COMMENT=	Fast two-pane file manager using GTK2


PTHREAD_OPTS+=	require

USE_TOOLS+=	gmake


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
