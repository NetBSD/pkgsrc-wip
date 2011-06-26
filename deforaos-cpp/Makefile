# $NetBSD: Makefile,v 1.1 2011/06/26 19:23:54 khorben Exp $

DISTNAME=	cpp-0.0.1
PKGNAME=	deforaos-cpp-0.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3542/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS C pre-processor

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
