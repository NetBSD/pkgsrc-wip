# $NetBSD: Makefile,v 1.25 2004/02/09 14:55:55 moubctez Exp $
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

GIMP_VER=		2.0pre3

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PKGCONFIG_OVERRIDE=	gimp-1.3.pc.in
PKGCONFIG_OVERRIDE+=	gimpthumb-1.3.pc.in
PKGCONFIG_OVERRIDE+=	gimpui-1.3.pc.in

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-print
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html/${PKGNAME}

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

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
.include "../../graphics/libwmf/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
