# $NetBSD: Makefile,v 1.6 2003/06/30 08:28:20 moubctez Exp $
#

DISTNAME=		gimp-${GIMP_VER}
PKGNAME=		gimp-current-${GIMP_VER}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.3/v${GIMP_VER}/ \
	ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.3/v${GIMP_VER}/ \
	ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.3/v${GIMP_VER}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		adam@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

BUILD_USES_MSGFMT=	yes

CONFLICTS+=		gimp<=1.2.3

GIMP_VER=		1.3.16

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GMAKE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-print
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html/${PKGNAME}

# Add settings for MPEG, LIBMPEG, and GAP_DECODE_MPEG to properly support
# the MPEG library from graphics/mpeg-lib that changed it's name, as the
# configure script will default to searching from -lmpeg.
#
CONFIGURE_ENV+=		MPEG="mpeg"
CONFIGURE_ENV+=		LIBMPEG="-lmpeg_lib"
CONFIGURE_ENV+=		GAP_DECODE_MPEG="gap_decode_mpeg"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

MAKE_ENV+=		X11BASE=${X11BASE}
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

BUILD_DEFS+=		GIMP_WITH_HELPBROWSER

pre-build:
	${BUILDLINK_CC} -o ${WRKSRC}/docs/pdb_self_doc			\
		${FILESDIR}/pdb_self_doc.c

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} ||				\
		${LN} -fs ${PREFIX}/share/aclocal/gimp.m4		\
			${LOCALBASE}/share/aclocal/gimp.m4

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/mpeg-lib/buildlink2.mk"
.if defined(GIMP_WITH_HELPBROWSER) && ${GIMP_WITH_HELPBROWSER} != "no" 
PLIST_SUBST+=	HELPBROWSER=""
.include "../../x11/gnome-libs/buildlink2.mk"
.else
PLIST_SUBST+=	HELPBROWSER="@comment "
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
