# $NetBSD: Makefile,v 1.2 2007/04/12 12:49:04 bsadewitz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-wip-1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/fonts/
DISTFILES=	# empty

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg wip package

PKG_DESTDIR_SUPPORT=	user-destdir


DEPENDS+=	editres-[0-9]*:../../wip/editres
DEPENDS+=	listres-[0-9]*:../../wip/listres
DEPENDS+=	luit-[0-9]*:../../wip/luit
DEPENDS+=	rgb-[0-9]*:../../wip/rgb
DEPENDS+=	xcalc-[0-9]*:../../wip/xcalc
DEPENDS+=	xdm-[0-9]*:../../wip/xdm
DEPENDS+=	xkill-[0-9]*:../../wip/xkill
DEPENDS+=	xlsfonts-[0-9]*:../../wip/xlsfonts
DEPENDS+=	xvidtune-[0-9]*:../../wip/xvidtune
DEPENDS+=	xvinfo-[0-9]*:../../wip/xvinfo


NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes

do-install:

.include "../../mk/bsd.pkg.mk"
