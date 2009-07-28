# $NetBSD: Makefile,v 1.7 2009/07/28 16:19:22 jihbed Exp $
#

DISTNAME=	tilda-0.9.6
PKGREVISION=	2
CATEGORIES=	x11 sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tilda/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://tilda.sourceforge.net/
COMMENT=	Terminal like the classic first-person-shooter games

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config intltool msgfmt gmake flex
USE_PKGLOCALEDIR=	yes
USE_DIRS+=	xdg-1.4

.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
