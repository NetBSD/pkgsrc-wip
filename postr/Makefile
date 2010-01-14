# $NetBSD: Makefile,v 1.1.1.1 2010/01/14 08:32:40 jihbed Exp $
#

DISTNAME=	postr-0.12.4
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/postr/0.12/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://projects.gnome.org/postr/
COMMENT=	GNOME flickr uploader
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
