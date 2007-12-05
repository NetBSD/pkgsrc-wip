# $NetBSD: Makefile,v 1.7 2007/12/05 06:29:49 netcap Exp $
#

DISTNAME=	e17-0.16.999.041
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=   http://www.yazzy.org/pkgsrc/e17/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightenment Window Manager, Development Release

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config automake autoconf
#USE_DIRS+=      xdg-1.4

CONF_FILES=	etc/enlightenment/sysactions.conf

CONFIGURE_ARGS+=	--enable-zoom --enable-fsstd --with-imlib2

PKG_OPTIONS_VAR=        PKG_OPTIONS.e17
PKG_SUPPORTED_OPTIONS=  dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.	include	"../../wip/edbus/buildlink3.mk"
.endif

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
