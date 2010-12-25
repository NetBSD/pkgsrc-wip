# $NetBSD: Makefile,v 1.14 2010/12/25 12:45:45 noud4 Exp $
#

DISTNAME=		blassic-0.10.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://www.blassic.org/bin/
EXTRACT_SUFX=		.tgz

PKG_OPTIONS_VAR=		PKG_OPTIONS.blassic
PKG_SUPPORTED_OPTIONS=		dont-use-x

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://blassic.org/
COMMENT=		Blassic is a classic Basic interpreter

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdont-use-x)
CONFIGURE_ARGS+=	--without-x
.else
.include "../../x11/libX11/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
