# $NetBSD: Makefile,v 1.8 2010/06/13 22:47:09 thomasklausner Exp $
#

DISTNAME=	katapult-0.3.2.1
PKGREVISION=	4
CATEGORIES=	local
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=katapult/}

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://katapult.kde.org/
COMMENT=	Allow faster access to applications, bookmarks, and other items

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
