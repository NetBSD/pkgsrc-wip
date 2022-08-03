# $NetBSD: Makefile,v 1.1 2014/08/10 00:06:55 thomasklausner Exp $

DISTNAME=	rem-2.6.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=baresip/}
GITHUB_PROJECT=	rem
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/baresip/rem
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
SUBST_SED.prefix+=	-e "s|} -lre|} ${COMPILER_RPATH_FLAG}"'$$$$'"{libdir} -lre|"
SUBST_STAGE.prefix=	pre-build

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/librem.a

.include "../../wip/libre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
