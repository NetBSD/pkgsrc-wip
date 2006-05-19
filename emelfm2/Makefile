# $NetBSD: Makefile,v 1.8 2006/05/19 16:51:16 ykomatsu Exp $
#

DISTNAME=	emelfm2-0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://emelfm2.net/rel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://emelfm2.net/
COMMENT=	Fast two-pane file manager using GTK2

PTHREAD_OPTS+=	require

USE_DIRS+=	xdg-1.2
USE_TOOLS+=	gmake

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
