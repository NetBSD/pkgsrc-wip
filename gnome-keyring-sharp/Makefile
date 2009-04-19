# $NetBSD: Makefile,v 1.2 2009/04/19 23:18:26 thomasklausner Exp $
#

DISTNAME=	gnome-keyring-sharp-1.0.0
CATEGORIES=	security
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gnome-keyring-sharp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://andrew.jorgensenfamily.us/2008/08/gnome-keyring-sharp/
COMMENT=	Fully managed implementation of libgnome-keyring

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	src/gnome-keyring-sharp-1.0.pc.in

.include "options.mk"

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
