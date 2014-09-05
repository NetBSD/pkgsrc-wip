# $NetBSD: Makefile,v 1.2 2014/09/05 08:06:00 thomasklausner Exp $

DISTNAME=	baresip-0.4.11
CATEGORIES=	net audio
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.creytiv.com/baresip.html
COMMENT=	SIP User-Agent with audio and video support
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
MAKE_FLAGS+=	LFLAGS=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libre}/lib
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	SYSROOT=${BUILDLINK_PREFIX.libre}
MAKE_FLAGS+=	USE_STDIO=1 USE_OSS=1

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|1"
SUBST_STAGE.prefix=	post-patch

.include "../../wip/libre/buildlink3.mk"
.include "../../wip/librem/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
