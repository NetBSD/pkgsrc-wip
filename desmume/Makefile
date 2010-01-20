# $NetBSD: Makefile,v 1.5 2010/01/20 11:52:35 thomasklausner Exp $
#

DISTNAME=	desmume-0.9.5
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=desmume/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://desmume.sourceforge.net/
COMMENT=	Nintendo DS emulator

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config
USE_LANGUAGES=	c c++

PKG_DESTDIR_SUPPORT=user-destdir

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/agg/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
