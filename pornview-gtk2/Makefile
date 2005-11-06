# $NetBSD: Makefile,v 1.2 2005/11/06 17:05:21 leonardschmidt Exp $
#

.include "../../wip/pornview/Makefile.common"

PKGNAME=		${DISTNAME:S/_0.2pre1.orig/-gtk2/}

COMMENT=		(GTK+ 2.0 interface)

CONFLICTS=		pornview-[0-9]*

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-gtk2

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
