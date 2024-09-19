# $NetBSD: Makefile,v 1.2 2012/11/14 00:16:04 othyro Exp $

DISTNAME=	Accessories-0.0.3
PKGNAME=	deforaos-accessories-0.0.3
CATEGORIES=	misc
MASTER_SITES=	https://www.defora.org/os/download/download/3700/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS Accessories
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
