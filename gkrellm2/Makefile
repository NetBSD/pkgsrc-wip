# $NetBSD: Makefile,v 1.6 2003/06/17 00:07:28 xtraeme Exp $
.include "Makefile.common"

GKRELLM_PKGBASE=	gkrellm
WRKSRC=			${GKRELLM_SRCDIR}

COMMENT=		GTK2 based system monitor

DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../wip/gkrellm2-share

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_PKGINSTALL=		YES
PTHREAD_OPTS=		require

SPECIAL_PERMS+=		${PREFIX}/bin/gkrellm ${ROOT_USER} kmem 2711

ONLY_FOR_PLATFORM=	NetBSD-* FreeBSD-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
ALL_TARGET=		freebsd
.else
ALL_TARGET=		netbsd
.endif
INSTALL_TARGET=		install_netbsd

MAKE_ENV+=		LINK_FLAGS=${EXPORT_SYMBOLS_LDFLAGS}

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
