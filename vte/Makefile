# $NetBSD: Makefile,v 1.3 2003/06/30 00:10:12 xtraeme Exp $
#

DISTNAME=	vte-0.10.29
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vte/0.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Terminal widget with improved accessibility and I18N support

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-gnome-pty-helper
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/vte.pc.in

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
