# $NetBSD: Makefile,v 1.3 2015/01/27 00:10:05 khorben Exp $

DISTNAME=	asm-0.2.0
PKGNAME=	deforaos-asm-0.2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3545/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS assembler and de-assembler

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../wip/deforaos-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
