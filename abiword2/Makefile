# $NetBSD: Makefile,v 1.1.1.1 2003/11/28 16:36:07 xtraeme Exp $
#

DISTNAME=		abiword-2.0.1-2
WRKSRC=			${WRKDIR}/${DISTNAME}/abi
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=abiword/}

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.abisource.com/
COMMENT=		ABiword 2.0

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_X11=		yes

USE_GNU_ICONV=		yes

MAKEFILE=		GNUmakefile

CONFIGURE_ARGS+=	--enable-gnome
CONFIGURE_ARGS+=	--enable-scripting
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-sys-wv
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-popt=${BUILDLINK_PREFIX.popt}
CONFIGURE_ARGS+=	--with-libjpeg-prefix=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-libpng=${BUILDLINK_PREFIX.png}

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../wip/wv/buildlink2.mk"
.include "../../wip/gucharmap/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../wip/fribidi/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
