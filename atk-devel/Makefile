# $NetBSD: Makefile,v 1.4 2004/03/17 11:48:56 mpasternak Exp $
#

DISTNAME=		atk-1.6.0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://developer.gnome.org/projects/gap/
COMMENT=		Version of devel/atk that links with wip/glib2-devel

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	${WRKSRC}/atk.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir="${LOCALBASE}/share/doc/html"

# glib-mkenums overflows a 2048kb stack on atkobject.h
UNLIMIT_RESOURCES=	stacksize

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/glib2-devel/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
