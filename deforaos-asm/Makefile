# $NetBSD: Makefile,v 1.1 2011/06/26 19:31:05 khorben Exp $

DISTNAME=	asm-0.2.0
PKGNAME=	deforaos-asm-0.2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3545/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS assembler and de-assembler

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../wip/deforaos-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
