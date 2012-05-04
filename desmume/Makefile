# $NetBSD: Makefile,v 1.10 2012/05/04 15:38:34 noud4 Exp $
#

DISTNAME=	desmume-0.9.8
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=desmume/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://desmume.sourceforge.net/
COMMENT=	Nintendo DS emulator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool perl pkg-config
USE_LANGUAGES=	c c++

PKG_DESTDIR_SUPPORT=user-destdir

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/agg/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkglext+=	gtkglext>=1.2.0nb4
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
