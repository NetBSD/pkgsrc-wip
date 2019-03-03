# $NetBSD: Makefile,v 1.17 2016/02/26 11:27:21 jperkin Exp $

PORTNAME=	xf86-video-scfb
PORTVERSION=	0.0.4

DISTNAME=	${PORTNAME}-${PORTVERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=rayddteam/}
GITHUB_TAG=	bdeb3bf153d6f841f15990119c07ee349c29866a

CATEGORIES=	x11
# EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@NetBSD.org
COMMENT=	X.Org syscons display driver

ONLY_FOR_PLATFORM=	FreeBSD-*-* DragonFly-*-*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
