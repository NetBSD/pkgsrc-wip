# $NetBSD: Makefile,v 1.11 2012/09/28 22:07:33 asau Exp $
#

DISTNAME=	emelfm2-0.1.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://emelfm2.net/rel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://emelfm2.net/
COMMENT=	Fast two-pane file manager using GTK2

PKG_DESTDIR_SUPPORT=	none

PTHREAD_OPTS+=	require

USE_TOOLS+=	gmake

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
