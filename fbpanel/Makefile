# $NetBSD: Makefile,v 1.3 2005/04/06 00:16:19 jeremy-c-reed Exp $
#

DISTNAME=		fbpanel-4.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fbpanel/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://fbpanel.sourceforge.net/
COMMENT=		Desktop panel with menu, pager, and other plugins

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
PKGMANDIR?=		man
MAKE_ENV+=		PKGMANDIR=${PKGMANDIR}
MANCOMPRESSED=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
