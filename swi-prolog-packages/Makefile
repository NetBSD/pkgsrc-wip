# $NetBSD: Makefile,v 1.1.1.1 2004/04/22 16:46:04 mpasternak Exp $

.include "../../wip/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-packages-${SWIPLVERS}

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Packages for SWI Prolog

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_READLINE=	yes	# uses rl_event_hook() interface
USE_GNU_TOOLS+=		make
USE_X11=		yes

CONFIGURE_ENV+=		PL=swi-prolog

.include "../../mk/bsd.prefs.mk"

post-configure:
	cd ${WRKSRC}/packages; \
	${SETENV} \
		CPP=${CPP} \
		gmake configure

BUILD_DIRS+=	${WRKSRC}/packages
INSTALL_DIRS+=	${WRKSRC}/packages

pre-build:
	${LN} -sf ${LOCALBASE}/bin/plld       ${WRKSRC}/src
	${LN} -sf ${LOCALBASE}/bin/swi-prolog ${WRKSRC}/src

.include "../../wip/swi-prolog-lite/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
