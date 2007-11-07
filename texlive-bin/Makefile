# $NetBSD: Makefile,v 1.3 2007/11/07 19:13:58 airhead Exp $
#

PKGNAME=	texlive-bin-${TEXLIVE_VERSION}
DISTNAME=	texlive_base-${TEXLIVE_VERSION}-src
WRKSRC=		${WRKDIR}/texlive_base-${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	http://students.dec.bournemouth.ac.uk/ebarrett/texlive/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeXLive programs, using Edd Barret's OpenBSD repository

CONFLICTS+=	teTeX-bin-[0-9]*
CONFLICTS+=	teTeX2-bin-[0-9]*
CONFLICTS+=	teTeX3-bin-[0-9]*

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
INFO_FILES=	yes

CONFIGURE_ENV+=	GNUMAKE=gmake

DEPENDS+=	t1utils>=[0-9]*:../../fonts/t1utils
DEPENDS+=	psutils>=[0-9]*:../../print/psutils

# Use pkgsrc versions instead of the ones shipped with livetex
CONFIGURE_ARGS+=--with-system-freetype2
CONFIGURE_ARGS+=--with-system-ncurses
CONFIGURE_ARGS+=--with-system-pnglib
CONFIGURE_ARGS+=--with-system-zlib
CONFIGURE_ARGS+=--with-system-t1lib
CONFIGURE_ARGS+=--with-system-gd
CONFIGURE_ARGS+=--without-t1utils
CONFIGURE_ARGS+=--without-psutils
# We still need to use icu from texlive for now

CONFIGURE_ARGS+=--with-fontconfig=${BUILDLINK_PREFIX.fontconfig}

CONFIGURE_ARGS+=--without-texinfo
CONFIGURE_ARGS+=--without-texi2html

.include "../../wip/texlive/Makefile.common"
.include "options.mk"

.include "../../mk/tex.buildlink3.mk"  # XXX
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
