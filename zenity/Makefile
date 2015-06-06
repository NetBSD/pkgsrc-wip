# $NetBSD: Makefile,v 1.11 2015/06/06 18:22:26 leot1990 Exp $
#

DISTNAME=	zenity-3.16.2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
GITHUB_TAG=	${PKGNAME_NOREV:C/[.-]/_/g:tu}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Display GNOME dialogs from the command line

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config autoreconf autoconf automake gm4 aclocal
USE_TOOLS+=		xgettext

BUILD_DEPENDS+=		gnome-common>=0:../../devel/gnome-common
BUILD_DEPENDS+=		yelp-tools>=0:../../wip/yelp-tools

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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
