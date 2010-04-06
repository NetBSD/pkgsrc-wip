# $NetBSD: Makefile,v 1.1.1.1 2010/04/06 06:06:14 marttikuparinen Exp $

DISTNAME=	pam_yubico-2.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	http://yubico-pam.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubico-pam/
COMMENT=	Pluggable authentication module for Yubikey

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../wip/ykclient/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
