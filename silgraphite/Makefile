# $NetBSD: Makefile,v 1.1.1.1 2008/11/24 08:10:14 minskim Exp $

DISTNAME=	silgraphite-2.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://silgraphite.sourceforge.net/
COMMENT=	Font engine for complex non-Roman writing systems

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-freetype --without-xft --without-pangographite

PKGCONFIG_OVERRIDE+=	engine/installed-top.pc.in
PKGCONFIG_OVERRIDE+=	engine/silgraphite.pc.in
PKGCONFIG_OVERRIDE+=	engine/uninstalled-top.pc.in
PKGCONFIG_OVERRIDE+=	wrappers/freetype/installed-top.pc.in
PKGCONFIG_OVERRIDE+=	wrappers/freetype/silgraphite-ft.pc.in
PKGCONFIG_OVERRIDE+=	wrappers/freetype/uninstalled-top.pc.in
PKGCONFIG_OVERRIDE+=	wrappers/xft/installed-top.pc.in
PKGCONFIG_OVERRIDE+=	wrappers/xft/silgraphite-xft.pc.in
PKGCONFIG_OVERRIDE+=	wrappers/xft/uninstalled-top.pc.in

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
