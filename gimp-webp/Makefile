# $NetBSD: Makefile,v 1.1 2014/10/10 21:51:40 nros Exp $

DISTNAME=	gimp-webp_0.2-0~29~raring1
PKGNAME=	gimp-webp-0.2
CATEGORIES=	graphics
MASTER_SITES=	http://ppa.launchpad.net/george-edison55/webp/ubuntu/pool/main/g/gimp-webp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/gimp-webp
COMMENT=	WebP Gimp I/O plugin
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

BUILD_TARGET=	file-webp
WRKSRC=		${WRKDIR}/recipe-{debupstream}-0~{revno}

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
