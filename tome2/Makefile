# $NetBSD: Makefile,v 1.3 2009/03/04 15:57:43 thomasklausner Exp $
#

DISTNAME=	tome-235-src
PKGNAME=	tome-2.3.5
CATEGORIES=	games
MASTER_SITES=	http://t-o-m-e.net/dl/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://t-o-m-e.net/dl/src/
COMMENT=	Troubles of Middle Earth

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

BUILD_DIRS=	src
MAKE_FILE=	makefile.std
BUILD_TARGET=	default

TOME2_SHAREDIR=	${PREFIX}/share/tome2
FILES_SUBST+=	TOME2_SHAREDIR=${TOME2_SHAREDIR:Q}

CONF_FILES_PERMS+= \
	/dev/null ${TOME2_SHAREDIR}/apex/scores.raw ${GAMEOWN} ${GAMEGRP} 0644

MAKE_FLAGS+= \
	LIBDIR=${TOME2_SHAREDIR:Q} \
	GAMEOWN=${GAMEOWN:Q} \
	GAMEGRP=${GAMEGRP:Q}

# Prevent the default score file to be installed.
pre-install:
	${RM} -f ${WRKSRC}/lib/apex/scores.raw

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
