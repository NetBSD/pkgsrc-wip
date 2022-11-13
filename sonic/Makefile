# $NetBSD$

DISTNAME=	release-0.2.0
PKGNAME=	${DISTNAME:S/release/sonic/}
WRKSRC=		${WRKDIR}/sonic-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=espeak-ng/sonic/archive/refs/tags/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espeak-ng/sonic
COMMENT=	Simple library to speed up or slow down speech
LICENSE=	apache-2.0

USE_LANGUAGES=	c
USE_TOOLS=	gmake
CFLAGS+=	-Wall -O3 -ansi -fPIC -pthread -Wl,-rpath=${PREFIX}/lib

CHECK_SHLIBS_SKIP=	bin/sonic

.include "../../mk/bsd.pkg.mk"
