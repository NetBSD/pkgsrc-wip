# $NetBSD: Makefile,v 1.9 2004/05/09 02:39:01 minskim Exp $
#

DISTNAME=		glib-2.4.0
PKGNAME=                ${DISTNAME:S/glib/glib2/}
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org/
COMMENT=		pkgsrc-wip version of devel/glib2

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
TEST_TARGET=		check
GNU_CONFIGURE=		yes
BUILD_USES_MSGFMT=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/ltmain.sh ${WRKSRC}/libtool

PKGCONFIG_OVERRIDE+=	glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
# FreeBSD needs this
CONFIGURE_ARGS+=	--with-libiconv=gnu
.endif

CONFIGURE_ENV+=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
