# $NetBSD: Makefile,v 1.2 2003/04/04 14:20:40 cubidou Exp $

PKGNAME=	gkrellm-2.1.8a
.include "Makefile.common"

COMMENT=	GTK2 based system monitor

DEPENDS+=		gkrellm-share-2.1.8a:../../wip/gkrellm2-share

USE_BUILDLINK2=		YES
USE_X11=		YES
PTHREAD_OPTS=		require

ALL_TARGET=		netbsd
INSTALL_TARGET=		install_netbsd

MAKE_ENV+=		LINK_FLAGS=${EXPORT_SYMBOLS_LDFLAGS}

WRKSRC=			${WRKDIR}/gkrellm-2.1.8

pre-build:
	${SED} -e s,@@PREFIX@@,${PREFIX}, <${WRKSRC}/src/gkrellm.h >${WRKSRC}/src/gkrellm.h.sed
	${MV} ${WRKSRC}/src/gkrellm.h.sed ${WRKSRC}/src/gkrellm.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm2
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm2/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm2/themes

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
