# $NetBSD: Makefile,v 1.2 2003/12/02 00:15:31 mpasternak Exp $

DISTNAME=		glib-2.2.3
PKGNAME=		${MINGW_PKG_PREFIX}${DISTNAME:S/glib/glib2/}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.2/ \
			${MASTER_SITE_GNOME:=sources/glib/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org/docs/glib_toc.html
COMMENT=		Some useful routines for C programming

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_PERL5=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gthread-2.0.pc.in

NO_CONFIGURE=		# defined
MAKEFILE=		makefile.mingw

BUILD_DEPENDS=		${MINGW_PKG_PREFIX}gettext-lib>=0.11.5:../../wip/mingw32-gettext-lib

.include "../../wip/mk/win32.pkg.mk"
