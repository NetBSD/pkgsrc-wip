# $NetBSD: Makefile,v 1.7 2003/09/15 04:59:04 cubidou Exp $
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

ONLY_FOR_PLATFORM=	NetBSD-* FreeBSD-* OpenBSD-* Linux-*

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		MODULES=src LINK_FLAGS=${EXPORT_SYMBOLS_LDFLAGS}

pre-build:
	${SED} -e s,@@PREFIX@@,${PREFIX}, <${WRKSRC}/src/gkrellm.h >${WRKSRC}/src/gkrellm.h.sed
	${MV} ${WRKSRC}/src/gkrellm.h.sed ${WRKSRC}/src/gkrellm.h

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
