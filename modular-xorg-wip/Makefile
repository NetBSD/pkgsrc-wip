# $NetBSD: Makefile,v 1.6 2008/01/29 10:34:48 tnn2 Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-wip-1.0
PKGREVISION=	4
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/fonts/
DISTFILES=	# empty

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg wip package

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	xlsfonts-[0-9]*:../../wip/xlsfonts
DEPENDS+=	xvidtune-[0-9]*:../../wip/xvidtune

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes

do-install:

.include "../../mk/bsd.pkg.mk"
