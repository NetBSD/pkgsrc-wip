# $NetBSD: Makefile,v 1.2 2012/03/08 23:02:20 pettai Exp $

DISTNAME=	pam_yubico-2.11
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	http://yubico-pam.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubico-pam/
COMMENT=	Pluggable authentication module for Yubikey

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

.include "../../wip/libyubikey/buildlink3.mk"
.include "../../wip/ykclient/buildlink3.mk"
.include "../../wip/ykpers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
