# $NetBSD: Makefile,v 1.2 2008/05/24 15:34:09 tnn2 Exp $
#

DISTNAME=	eq-xmms-0.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=equ/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	http://equ.sourceforge.net/
COMMENT=	Equalizer plugin for XMMS not just for MP3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-mmx
CONFIGURE_ARGS+=	--enable-sse
CONFIGURE_ARGS+=	--enable-sse2
CONFIGURE_ARGS+=	--enable-sse-filters
USE_LIBTOOL=		yes
#USE_TOOLS+=		gmake

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
