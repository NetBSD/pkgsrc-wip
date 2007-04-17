# $NetBSD: Makefile,v 1.13 2007/04/17 19:17:48 briandealwis Exp $
#

DISTNAME=		fbpanel-4.8
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fbpanel/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		bsd@cs.ubc.ca
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

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
