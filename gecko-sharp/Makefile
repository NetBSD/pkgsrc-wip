# $NetBSD: Makefile,v 1.1.1.1 2009/03/23 22:31:06 jihbed Exp $
#

DISTNAME=	gecko-sharp-2.0-0.13
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gecko-sharp2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://mono-project.com/GeckoSharp/
COMMENT=	GeckoSharp is a wrapper for the GtkEmbedMoz widget

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
