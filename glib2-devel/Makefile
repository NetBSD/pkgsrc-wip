# $NetBSD: Makefile,v 1.3 2004/03/17 11:48:56 mpasternak Exp $
#

DISTNAME=		glib-2.4.0
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Development (unstable) version of devel/glib2

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gthread-2.0.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

GLIB_USE_GNU_ICONV=		no

.if ${OPSYS} == "FreeBSD"
GLIB_USE_GNU_ICONV=		no
.endif

.if ${GLIB_USE_GNU_ICONV} == [Nn][Oo]
CONFIGURE_ARGS+=	--with-libiconv=native
.else
CONFIGURE_ARGS+=	--with-libiconv=gnu
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
