# $NetBSD: Makefile,v 1.13 2015/06/06 18:48:10 krytarowski Exp $
#

DISTNAME=	zenity-3.18.1
PKGREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/zenity/3.18/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Display GNOME dialogs from the command line
LICENSE=	gnu-lgpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config autoreconf autoconf
USE_TOOLS+=		automake gm4 aclocal xgettext autopoint

BUILD_DEPENDS+=		gnome-common-[0-9]*:../../devel/gnome-common
BUILD_DEPENDS+=		yelp-tools-[0-9]*:../../wip/yelp-tools

pre-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh

.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
#.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
