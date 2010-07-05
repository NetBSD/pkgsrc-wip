# $NetBSD: Makefile,v 1.4 2010/07/05 20:03:47 ryo-on Exp $
#

DISTNAME=	sakura-2.3.8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.pleyades.net/david/projects/sakura/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.pleyades.net/david/sakura.php
COMMENT=	The sakura is a terminal emulator based on GTK and VTE supports tab

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config pod2man
USE_CMAKE=	yes

SUBST_CLASSES+=			fix-man-path
SUBST_STAGE.fix-man-path=	post-patch
SUBST_MESSAGE.fix-man-path=	Fix path for man1.
SUBST_FILES.fix-man-path=	CMakeLists.txt
SUBST_SED.fix-man-path=		-e 's,share/man/man1,man/man1,g'

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.vte+=	vte>=0.16.15
.include "../../x11/vte/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
