# $NetBSD: Makefile,v 1.2 2012/03/08 23:05:46 pettai Exp $
#

DISTNAME=	ykpers-1.6.3
CATEGORIES=	security
MASTER_SITES=	http://yubikey-personalization.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubikey-personalization/
COMMENT=	Yubico's YubiKey re-programming toolkit
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	ykpers-1.pc.in

.include "../../wip/libyubikey/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
