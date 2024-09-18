# $NetBSD$

VERSION_DIST=	0.8.0-rc7
VERSION_PKG=	0.8.0rc7
DISTNAME=	g-golf-${VERSION_DIST}
PKGNAME=	g-golf-${VERSION_PKG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=g-golf/}

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
.include "../../lang/guile30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
