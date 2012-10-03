# $NetBSD: Makefile,v 1.3 2012/10/03 18:15:32 asau Exp $
#

DISTNAME=	netwmpager-2.04
CATEGORIES=	wm
MASTER_SITES=	http://downloads.sourceforge.net/project/sf-xpaint/netwmpager/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	# none
COMMENT=	EWMH (NetWM) compatible pager
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/examples

.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
