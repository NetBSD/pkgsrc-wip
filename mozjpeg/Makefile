# $NetBSD: Makefile,v 1.1 2014/08/07 09:06:08 thomasklausner Exp $

DISTNAME=	mozjpeg-${VERSION}
VERSION=	2.1
CATEGORIES=	graphics
MASTER_SITES=	-https://github.com/mozilla/mozjpeg/archive/v${VERSION}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/mozjpeg/
COMMENT=	Mozilla JPEG Encoder Project
LICENSE=	modified-bsd

BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
