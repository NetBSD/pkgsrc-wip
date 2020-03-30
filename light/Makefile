# $NetBSD$

DISTNAME=	light-1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=haikarainen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/haikarainen/light/
COMMENT=	Control backlights (and other hardware lights) under Linux
LICENSE=	gnu-gpl-v3

ONLY_FOR_PLATFORM+=	Linux-*-*

USE_TOOLS+=	autoconf automake

GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
