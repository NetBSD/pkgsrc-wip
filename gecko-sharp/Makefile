# $NetBSD: Makefile,v 1.3 2009/06/19 22:27:15 jihbed Exp $
#

DISTNAME=	gecko-sharp-2.0-0.13
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gecko-sharp2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://mono-project.com/GeckoSharp/
COMMENT=	GeckoSharp is a wrapper for the GtkEmbedMoz widget
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=		user-destdir
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=		c

PKGCONFIG_OVERRIDE+=	gecko-sharp-2.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
