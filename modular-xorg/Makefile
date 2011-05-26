# $NetBSD: Makefile,v 1.1.1.1 2011/05/26 17:42:21 mrampke Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XORG:=/}
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg meta-package

META_PACKAGE=	yes

DEPENDS+=	modular-xorg-libs-[0-9]*:../../meta-pkgs/modular-xorg-libs
DEPENDS+=	modular-xorg-drivers-[0-9]*:../../meta-pkgs/modular-xorg-drivers
DEPENDS+=	modular-xorg-apps-[0-9]*:../../meta-pkgs/modular-xorg-apps
DEPENDS+=	modular-xorg-fonts-[0-9]*:../../meta-pkgs/modular-xorg-fonts
DEPENDS+=	modular-xorg-server-[0-9]*:../../x11/modular-xorg-server

.include "../../mk/bsd.pkg.mk"
