# $NetBSD: Makefile,v 1.9 2006/11/11 13:26:33 shattered Exp $
#

DISTNAME=		fbpanel-4.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fbpanel/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://fbpanel.sourceforge.net/
COMMENT=		Desktop panel with menu, pager, and other plugins

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--cpu=on
.else
CONFIGURE_ARGS+=	--cpu=off
.endif

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

MAKE_ENV+=		PKGMANDIR=${PKGMANDIR:Q}
MANCOMPRESSED=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
