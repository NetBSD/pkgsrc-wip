# $NetBSD: Makefile,v 1.1.1.1 2010/09/28 15:04:55 ggergely Exp $
#

DISTNAME=	sword-1.6.1
CATEGORIES=	misc
MASTER_SITES=	http://www.crosswire.org/ftpmirror/pub/sword/source/v1.6/

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://www.crosswire.org/ftpmirror/pub/sword/source/v1.6/
COMMENT=	SWORD Bible study software libraries and tools
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
# TODO: fortran is a bogus due to autohell's brokeage, fix it
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=	--with-clucene=${BUILDLINK_PREFIX.libclucene}

PKGCONFIG_OVERRIDE+=	sword.pc.in

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
