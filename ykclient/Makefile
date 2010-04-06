# $NetBSD: Makefile,v 1.1.1.1 2010/04/06 06:00:13 marttikuparinen Exp $

DISTNAME=	ykclient-2.3
CATEGORIES=	security
MASTER_SITES=	http://yubico-c-client.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubico-c/
COMMENT=	Libraries for online validation of Yubikey OTPs

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
