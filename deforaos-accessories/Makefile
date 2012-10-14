# $NetBSD: Makefile,v 1.1 2012/10/14 19:32:56 khorben Exp $

DISTNAME=	Accessories-0.0.3
PKGNAME=	deforaos-accessories-0.0.3
CATEGORIES=	wip
MASTER_SITES=	http://www.defora.org/os/download/download/3700/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS Accessories

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
