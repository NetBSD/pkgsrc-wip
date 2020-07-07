# $NetBSD$

DISTNAME=	plan9port-20200622
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=9fans/}
GITHUB_TAG=	95ab1308b410ad8547e38e47ec4a36f560dcece5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://9fans.github.io/plan9port/
COMMENT=	Plan 9 from User Space
LICENSE=	lucent

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run perl

REPLACE_BASH+=	src/cmd/rc/checkparse

REPLACE_PERL+=	dist/addsrclinks
REPLACE_PERL+=	dist/fixurls
REPLACE_PERL+=	unix/man/fixurls

do-build:
	cd ${WRKSRC} && ./INSTALL -b

do-install:
	cd ${WRKSRC} && ./INSTALL -c

.include "../../fonts/fontconfig/buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
