# $NetBSD$

DISTNAME=	gsegrafix-1.0.6
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.gnu.org/gnu/gsegrafix/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.gnu.org/software/gsegrafix/
COMMENT=	GNOME canvas for creating scientific and engineering plots
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
