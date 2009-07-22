# $NetBSD: Makefile,v 1.3 2009/07/22 09:53:11 thomasklausner Exp $
#

DISTNAME=	desmume-0.8
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=desmume/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://desmume.sourceforge.net/
COMMENT=	Nintendo DS emulator

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config

PKG_DESTDIR_SUPPORT=user-destdir

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
