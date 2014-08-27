# $NetBSD: Makefile,v 1.5 2014/08/27 10:40:43 thomasklausner Exp $

DISTNAME=	libopenmpt-0.2.4218
CATEGORIES=	audio
MASTER_SITES=	http://buildbot.openmpt.org/builds/auto/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lib.openmpt.org/libopenmpt/
COMMENT=	Library to decode tracked music files into a raw PCM audio stream (development version)
LICENSE=	modified-bsd

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE=		bin/libopenmpt.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "options.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
