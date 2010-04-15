# $NetBSD: Makefile,v 1.4 2010/04/15 15:47:39 khorben Exp $
#

DISTNAME=	libSystem-0.1.3
PKGNAME=	deforaos-libsystem-0.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3301/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS core system library

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
