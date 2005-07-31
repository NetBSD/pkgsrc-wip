# $NetBSD: Makefile,v 1.8 2005/07/31 02:43:47 ivaniclixx Exp $
#

DISTNAME=		blassic-0.10.0
CATEGORIES=		lang
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/blassic/
EXTRACT_SUFX=		.tgz

PKG_OPTIONS_VAR=		PKG_OPTIONS.blassic
PKG_SUPPORTED_OPTIONS=		dont-use-x

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://blassic.org
COMMENT=		Blassic is a classic Basic interpreter

GNU_CONFIGURE=		yes

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdont-use-x)
CONFIGURE_ARGS+=	--without-x
.else
.include "../../mk/x11.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
