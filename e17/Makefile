# $NetBSD: Makefile,v 1.6 2007/12/04 04:39:00 netcap Exp $
#

DISTNAME=	enlightenment-0.16.999.041
PKGNAME=	${DISTNAME:S/enlightenment/e17/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightenment Window Manager, Development Release

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKG_OPTIONS_VAR=        PKG_OPTIONS.e17
PKG_SUPPORTED_OPTIONS=  dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-edbus
.	include	"../../wip/edbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-edbus
.endif

.include	"../../wip/eet/buildlink3.mk"
.include	"../../wip/edje/buildlink3.mk"
.include	"../../wip/efreet/buildlink3.mk"
.include	"../../wip/embryo/buildlink3.mk"
.include	"../../wip/evas/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
