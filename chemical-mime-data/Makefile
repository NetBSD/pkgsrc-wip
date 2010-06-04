# $NetBSD: Makefile,v 1.2 2010/06/04 11:53:33 jihbed Exp $
#

DISTNAME=	chemical-mime-data-0.1.94
CATEGORIES=	biology
MASTER_SITES=	http://garr.dl.sourceforge.net/project/chemical-mime/chemical-mime-data/0.1.94/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://chemical-mime.sourceforge.net/
COMMENT=	chemical mime and file type support for desktops
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=  yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake
USE_LANGUAGES=	c c++

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

PKGCONFIG_OVERRIDE+=	chemical-mime-data.pc.in

.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
