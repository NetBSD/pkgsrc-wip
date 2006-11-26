# $NetBSD: Makefile,v 1.3 2006/11/26 23:09:25 larnor Exp $

DISTNAME=	gaim-icb-20061112
CATEGORIES=	chat
MASTER_SITES=	http://nic.com.pl/~alek/gaim-icb/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://nic.com.pl/~alek/gaim-icb/
COMMENT=	ICB plugin for GAIM 2

USE_TOOLS+=	pkg-config

USE_LIBTOOL=	yes
NO_CONFIGURE=	yes

LTCOMPILE=	${SHLIBTOOL} --mode=compile ${CC}
LTLINK=		${SHLIBTOOL} --mode=link ${CC}
LTINSTALL=	${SHLIBTOOL} --mode=install ${INSTALL_LIB}
CFLAGS+=	-DHAVE_CONFIG_H `pkg-config gaim --cflags`
LDFLAGS+=	-module -avoid-version -rpath ${GAIM_PLUGIN_DIR}	\
		`pkg-config gaim --libs`

GAIM_PLUGIN_DIR=	${PREFIX}/lib/gaim
GAIM_PIXMAPS_DIR=	${PREFIX}/share/pixmaps/gaim

do-build:
	cd ${WRKSRC} && ${LTCOMPILE} ${CFLAGS} -I. -c icb.c
	cd ${WRKSRC} && ${LTLINK} ${LDFLAGS} -o libicb.la icb.lo

do-install:
	${INSTALL_LIB_DIR} ${GAIM_PLUGIN_DIR}
	cd ${WRKSRC} && ${LTINSTALL} libicb.la ${GAIM_PLUGIN_DIR}
	${INSTALL_DATA_DIR} ${GAIM_PIXMAPS_DIR}/status/default
	cd ${WRKSRC} && ${INSTALL_DATA} icb.png				\
		${GAIM_PIXMAPS_DIR}/status/default

.include "../../wip/gaim/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
