# $NetBSD: Makefile,v 1.1.1.1 2003/12/29 14:41:07 mpasternak Exp $
#

DISTNAME=		glib-2.3.1
PKGNAME=		${DISTNAME:S/glib-/glib2-devel-/}
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.3/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Development (unstable) version of devel/glib2

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gthread-2.0.pc.in
GNU_CONFIGURE=		yes

CONFLICTS=		glib2-*

.include "../../mk/bsd.prefs.mk"

GLIB_USE_GNU_ICONV=		no

.if ${OPSYS} == "FreeBSD"
GLIB_USE_GNU_ICONV=		no
.endif

.if ${GLIB_USE_GNU_ICONV} == [Nn][Oo]
CONFIGURE_ARGS+=	--with-libiconv=native
.else
CONFIGURE_ARGS+=	--with-libiconv=gnu
.include "../../devel/gettext-lib/buildlink2.mk"
.endif

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
