# $NetBSD: Makefile,v 1.9 2012/08/06 15:45:40 mwilhelmy Exp $

DISTNAME=		iodine-0.6.0-rc1
PKGNAME=		iodine-0.6.0rc1
CATEGORIES=		net
MASTER_SITES=		http://code.kryo.se/iodine/

MAINTAINER=		mwilhelmy@users.sourceforge.net
HOMEPAGE=		http://code.kryo.se/iodine/
COMMENT=		Tool to tunnel IPv4 over DNS
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_USERS=		iodine:iodine
PKG_GROUPS=		iodine

BUILD_DEFS+=		VARBASE
MAKE_DIRS=		${VARBASE}/chroot
OWN_DIRS=		${VARBASE}/chroot/iodine

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
