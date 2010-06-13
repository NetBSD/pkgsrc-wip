# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:21 thomasklausner Exp $
#

DISTNAME=	webkit-sharp-0.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/webkit-sharp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
# could not find real homepage
#HOMEPAGE=	http://ftp.novell.com/pub/mono/sources/webkit-sharp/
COMMENT=	Webkit-sharp Bindings webkit-gtk under C\#
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	sources/webkit-sharp.pc.in

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=1.1.3
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
