# $NetBSD: Makefile,v 1.6 2010/03/16 19:43:04 jihbed Exp $
#

DISTNAME=	gnome-keyring-sharp-1.0.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/gnome-keyring-sharp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
#http://andrew.jorgensenfamily.us/2008/08/gnome-keyring-sharp/
HOMEPAGE=	http://ftp.novell.com/pub/mono/sources/gnome-keyring-sharp/ 
COMMENT=	Mono implementation of libgnome-keyring

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	# none


PKGCONFIG_OVERRIDE+=	src/gnome-keyring-sharp-1.0.pc.in

CONFIGURE_ARGS+=	--disable-monodoc

.include "options.mk"

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
