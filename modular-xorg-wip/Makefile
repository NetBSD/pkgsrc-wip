# $NetBSD: Makefile,v 1.3 2007/04/20 08:49:03 bsadewitz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-wip-1.0
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/fonts/
DISTFILES=	# empty

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg wip package

PKG_DESTDIR_SUPPORT=	user-destdir


DEPENDS+=	xdm-[0-9]*:../../wip/xdm
DEPENDS+=	xlsfonts-[0-9]*:../../wip/xlsfonts


NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes

do-install:

.include "../../mk/bsd.pkg.mk"
