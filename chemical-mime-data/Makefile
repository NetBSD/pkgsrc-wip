# $NetBSD: Makefile,v 1.1.1.1 2010/05/26 16:17:22 jihbed Exp $
#

DISTNAME=	chemical-mime-data-0.1.94
CATEGORIES=	biology
MASTER_SITES=	http://garr.dl.sourceforge.net/project/chemical-mime/chemical-mime-data/0.1.94/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://chemical-mime.sourceforge.net/
COMMENT=	TODO: Short description of the package
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
