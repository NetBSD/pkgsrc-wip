# $NetBSD: Makefile,v 1.5 2011/03/10 12:18:31 ryo-on Exp $
#

DISTNAME=	chemical-mime-data-0.1.94
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://garr.dl.sourceforge.net/project/chemical-mime/chemical-mime-data/0.1.94/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://chemical-mime.sourceforge.net/
COMMENT=	Chemical mime and file type support for desktops
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=  yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake
USE_LANGUAGES=	c c++

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

PKGCONFIG_OVERRIDE+=	chemical-mime-data.pc.in

.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
