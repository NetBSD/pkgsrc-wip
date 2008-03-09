# $NetBSD: Makefile,v 1.20 2008/03/09 21:10:15 hoka_adam Exp $

PKGNAME=		abuse_sdl-0.7.1
DISTNAME=		${PKGNAME:S/_sdl//}
CATEGORIES=		games
MASTER_SITES=		http://abuse.zoy.org/raw/Downloads/
DISTFILES=		${DEFAULT_DISTFILES} \
			abuse-frabs-2.11.tar.gz

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://www.labyrinth.net.au/~trandor/abuse/
COMMENT=		Port of the Abuse side scroller to SDL

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--program-suffix=-sdl

PKG_DESTDIR_SUPPORT=	user-destdir

CPPFLAGS+=		-DPREFIX=\"${PREFIX:Q}\"

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	src/sdlport/setup.cpp
SUBST_SED.path=		-e 's,/var/games/abuse,${PREFIX}/share/abuse_sdl,g'
SUBST_MESSAGE.path=	Fixing hardcoded paths.

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/abuse_sdl
	cd ${DESTDIR}${PREFIX}/share/abuse_sdl && \
		(${CP} -R ${WRKDIR}/abuse-frabs-2.11/* . && \
		${CHOWN} -R ${SHAREOWN} . && ${CHGRP} -R ${SHAREGRP} . && \
		${FIND} . -type f -exec ${CHMOD} ${SHAREMODE} '{}' ';' && \
		${FIND} . -name '*.exe' -exec rm -f '{}' ';' && \
		${FIND} . -type d -exec ${CHMOD} ${BINMODE} '{}' ';')

.include "../../graphics/glu/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
