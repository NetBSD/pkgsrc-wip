# $NetBSD: Makefile,v 1.2 2012/09/28 21:24:33 asau Exp $

DISTNAME=	configure-0.0.7
PKGNAME=	deforaos-configure-0.0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3294/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS automated Makefile generation tool

LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
