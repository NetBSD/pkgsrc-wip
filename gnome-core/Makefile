# $NetBSD: Makefile,v 1.1 2015/07/12 00:20:15 thomasklausner Exp $

DISTNAME=	gnome-core-3.20.2
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNOME core libraries

META_PACKAGE=	yes

# see https://git.gnome.org/browse/
DEPENDS+=	adwaita-icon-theme-[0-9]*:../../graphics/adwaita-icon-theme
DEPENDS+=	at-spi2-atk-[0-9]*:../../devel/at-spi2-atk
DEPENDS+=	at-spi2-core-[0-9]*:../../devel/at-spi2-core
DEPENDS+=	atk-[0-9]*:../../devel/atk
DEPENDS+=	atkmm-[0-9]*:../../devel/atkmm
DEPENDS+=	bijiben-[0-9]*:../../wip/bijiben
DEPENDS+=	cantarell-fonts-[0-9]*:../../fonts/cantarell-fonts
DEPENDS+=	caribou-[0-9]*:../../wip/caribou
DEPENDS+=	clutter-[0-9]*:../../graphics/clutter
DEPENDS+=	clutter-gst-[0-9]*:../../wip/clutter-gst
DEPENDS+=	clutter-gtk-[0-9]*:../../graphics/clutter-gtk
DEPENDS+=	cogl-[0-9]*:../../graphics/cogl
DEPENDS+=	dconf-[0-9]*:../../devel/dconf
DEPENDS+=	dconf-editor-[0-9]*:../../devel/dconf-editor
DEPENDS+=	epiphany-[0-9]*:../../wip/epiphany
DEPENDS+=	evince3-[0-9]*:../../print/evince3
DEPENDS+=	evolution-data-server-[0-9]*:../../wip/evolution-data-server
DEPENDS+=	gnome-tracker-[0-9]*:../../wip/gnome-tracker

# TODO

.include "../../mk/bsd.pkg.mk"
