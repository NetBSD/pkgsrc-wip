# $NetBSD: Makefile,v 1.14 2010/11/13 02:46:40 minskim Exp $

PKGNAME=	texlive-bin-${TEXLIVE_VERSION}
DISTNAME=	texlive_base-${TEXLIVE_VERSION}-src
WRKSRC=		${WRKDIR}/texlive_base-${TEXLIVE_VERSION}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://students.dec.bournemouth.ac.uk/ebarrett/texlive/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeXLive programs, using Edd Barret's OpenBSD repository

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
INFO_FILES=	yes

CONFIGURE_ENV+=	GNUMAKE=gmake

DEPENDS+=	t1utils-[0-9]*:../../fonts/t1utils
DEPENDS+=	psutils-[0-9]*:../../print/psutils

# Use pkgsrc versions instead of the ones shipped with livetex
CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-ncurses
CONFIGURE_ARGS+=	--with-system-pnglib
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-system-t1lib
CONFIGURE_ARGS+=	--with-system-gd
CONFIGURE_ARGS+=	--without-t1utils
CONFIGURE_ARGS+=	--without-psutils
# We still need to use icu from texlive for now

CONFIGURE_ARGS+=	--with-fontconfig=${BUILDLINK_PREFIX.fontconfig}

CONFIGURE_ARGS+=	--without-texinfo
CONFIGURE_ARGS+=	--without-texi2html
CONFIGURE_ARGS+=	--disable-multiplatform

.include "../../wip/texlive/Makefile.common"
.include "options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
