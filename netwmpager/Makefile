# $NetBSD: Makefile,v 1.2 2012/09/13 13:45:21 thomasklausner Exp $
#

DISTNAME=	netwmpager-2.04
CATEGORIES=	wm
MASTER_SITES=	http://downloads.sourceforge.net/project/sf-xpaint/netwmpager/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	# none
COMMENT=	EWMH (NetWM) compatible pager
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/examples

.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
