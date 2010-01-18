# $NetBSD: Makefile,v 1.6 2010/01/18 09:38:26 thomasklausner Exp $
#

DISTNAME=	krusader-2.1.0-beta1
PKGREVISION=	2
CATEGORIES=	kde sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=krusader/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://krusader.sourceforge.net/
COMMENT=	Advanced twin-panel (commander-style) file-manager for KDE 4.x

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+= automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	perl msgfmt
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
