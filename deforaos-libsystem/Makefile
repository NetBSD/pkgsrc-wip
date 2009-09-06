# $NetBSD: Makefile,v 1.2 2009/09/06 23:26:04 khorben Exp $
#

DISTNAME=	libSystem-0.1.2
PKGNAME=	deforaos-libsystem-0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3264/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS core system library

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
