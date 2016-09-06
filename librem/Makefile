# $NetBSD: Makefile,v 1.1 2014/08/10 00:06:55 thomasklausner Exp $

DISTNAME=	rem-0.4.7
PKGNAME=	lib${DISTNAME}
CATEGORIES=	net audio
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.creytiv.com/rem.html
COMMENT=	Portable library for real-time audio and video processing
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
MAKE_FLAGS+=	LFLAGS=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libre}/lib
MAKE_FLAGS+=	PREFIX=${PREFIX}

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|1"
SUBST_STAGE.prefix=	post-patch

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/librem.a

.include "../../wip/libre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
