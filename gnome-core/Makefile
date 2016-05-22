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
#DEPENDS+=	bijiben-[0-9]*:../../wip/bijiben

# TODO

.include "../../mk/bsd.pkg.mk"
