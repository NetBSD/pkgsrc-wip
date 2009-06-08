# $NetBSD: Makefile,v 1.7 2009/06/08 09:41:05 obache Exp $
#

DISTNAME=	swftools-0.9.0
CATEGORIES=	graphics converters
MASTER_SITES=	http://www.swftools.org/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.swftools.org/
COMMENT=	Collection of SWF manipulation and creation utilities

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake yacc
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

# png2swf already installed as part of ming. 
CONFIGURE_ENV+=		DISABLEPNG2SWF=true

PKG_OPTIONS_VAR=	PKG_OPTIONS.swftools
PKG_SUPPORTED_OPTIONS=	lame

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+=	--enable-lame
.include "../../audio/lame/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}/${PREFIX}/${PKGMANDIR}

.include "../../wip/avifile-devel/buildlink3.mk"
BUILDLINK_INCDIRS.fontconfig=	include/fontconfig
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
