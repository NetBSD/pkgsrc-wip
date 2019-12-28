# $NetBSD: Makefile,v 1.9 2012/10/01 21:43:24 asau Exp $

DISTNAME=	jp2a-${GITHUB_TAG:S/v//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=cslarsen/}
GITHUB_TAG=	v1.0.7

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	https://github.com/cslarsen/jp2a
COMMENT=	JPEG to ASCII converter
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	automake autoconf autoreconf
GNU_CONFIGURE=	yes

pre-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -vi)

.include "options.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
