# $NetBSD: Makefile,v 1.21 2011/12/16 15:50:05 seanboudreau Exp $
#

DISTNAME=		fbpanel-4.12
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fbpanel/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		bsd@cs.ubc.ca
HOMEPAGE=		http://fbpanel.sourceforge.net/
COMMENT=		Desktop panel with menu, pager, and other plugins

USE_TOOLS+=		gmake pkg-config
HAS_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--cpu=on
PLIST_SUBST+=	CPUPLUGIN=""
.else
CONFIGURE_ARGS+=	--cpu=off
PLIST_SUBST+=	CPUPLUGIN="@comment "
.endif

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
MAKE_ENV+=		PKGMANDIR=${PKGMANDIR:Q}
MANCOMPRESSED=		yes

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
