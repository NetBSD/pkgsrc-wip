# $NetBSD$

DIST_VER=	0.8.0-rc-2
PKG_VER=	0.8.0rc2
DISTNAME=	g-golf-${DIST_VER}
PKGNAME=	g-golf-${PKG_VER}
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/gnu/g-golf/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/g-golf/
COMMENT=	Guile Object Library for GNOME
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config makeinfo

CONFIGURE_ARGS+=	--with-guile-site=yes

TEXINFO_REQD=	6
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	meta/g-golf-1.0.pc.in

TEST_TARGET=	check
# \todo need guile-lib
TEST_DEPENDS+=	guile-lib>0:../../devel/guile-lib
TEST_DEPENDS+=	gtk3+>=3:../../x11/gtk3
# example depends: 
#TEST_DEPENDS+=	libadwaita>0:../../devel/libadwaita
#TEST_DEPENDS+=	guile-cairo>0:../../graphics/guile-cairo
#TEST_DEPENDS+=	gtk4+>=4:../../x11/gtk4

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
