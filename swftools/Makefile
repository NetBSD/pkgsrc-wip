# $NetBSD: Makefile,v 1.1.1.1 2005/07/31 11:05:47 obache Exp $
#

DISTNAME=	swftools-0.6.3
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.quiss.org/swftools/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.quiss.org/swftools/
COMMENT=	Collection of SWF manipulation and creation utilities

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.swftools
PKG_SUPPORTED_OPTIONS=	lame

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+= --enable-lame
.include "../../audio/lame/buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-lame
.endif

.include "../../wip/avifile-devel/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../wip/ming/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
