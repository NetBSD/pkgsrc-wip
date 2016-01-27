# $NetBSD: Makefile,v 1.13 2015/06/06 18:39:04 krytarowski Exp $
#

.include "Makefile.common"

# https://git.gnome.org/browse/vte/

CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Terminal widget with improved accessibility and I18N support
LICENSE=	gnu-lgpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config autoreconf autoconf automake gettext-m4
USE_LANGUAGES+=		c c++

CONFIGURE_ARGS+=	--enable-Bsymbolic=auto
# XXX: option
CONFIGURE_ARGS+=	--enable-introspection
# XXX: option
CONFIGURE_ARGS+=	--enable-python

pre-configure:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh NOCONFIGURE=1

.include "../../devel/gperf/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.40.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
# for FC_WIDTH
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.1.93
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
# requires gtk3 >= 3.8.0
#BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
