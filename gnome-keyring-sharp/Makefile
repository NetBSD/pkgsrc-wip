# $NetBSD: Makefile,v 1.1.1.1 2009/04/18 00:31:51 jihbed Exp $
#

DISTNAME=	gnome-keyring-sharp-1.0.0
CATEGORIES=	security
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gnome-keyring-sharp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ftp.novell.com/pub/mono/sources/gnome-keyring-sharp/
COMMENT=	Fully managed implementation of libgnome-keyring

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/gnome-keyring-sharp-1.0.pc.in

CONFIGURE_ARGS+=	--disable-monodoc


.include "options.mk"

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
