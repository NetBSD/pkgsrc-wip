# $NetBSD: Makefile,v 1.19 2004/01/12 03:57:14 blef Exp $
#

DISTNAME=		gimp-${GIMP_VER}
PKGNAME=		gimp-current-${GIMP_VER}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v2.0/testing/ \
	ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v2.0/testing/ \
	ftp://ftp.cs.umn.edu/pub/gimp/gimp/v2.0/testing/ \
	ftp://ftp.tuwien.ac.at/graphics/gimp/gimp/v2.0/testing/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		adam@NetBSD.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

BUILD_USES_MSGFMT=	yes
BUILDLINK_DEPENDS.freetype2=	freetype2>=2.1.4

CONFLICTS+=		gimp<=1.2.3

GIMP_VER=		2.0pre1

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

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

MAKE_ENV+=		X11BASE=${X11BASE}
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

pre-build:
	${BUILDLINK_CC} -o ${WRKSRC}/docs/pdb_self_doc			\
		${FILESDIR}/pdb_self_doc.c

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} ||				\
		${LN} -fs ${PREFIX}/share/aclocal/gimp.m4		\
			${LOCALBASE}/share/aclocal/gimp.m4

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
