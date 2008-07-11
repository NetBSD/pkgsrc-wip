# $NetBSD: Makefile,v 1.1.1.1 2008/07/11 03:07:10 dillo Exp $
#

DISTNAME=	desmume-0.8
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=desmume/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://desmume.sourceforge.net/
COMMENT=	Nintendo DS emulator

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl pkg-config
USE_DIRS+=	xdg-1.4

PKG_DESTDIR_SUPPORT=user-destdir

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
