# $NetBSD: Makefile,v 1.3 2003/04/07 17:54:31 cubidou Exp $
.include "../../wip/gkrellm2/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-server
COMMENT=		monitoring daemon remotely accessible by a GKrellM client
DEPENDS+=		gkrellm-share-${GKRELLM_VERSION}:../../wip/gkrellm2-share

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
PTHREAD_OPTS=		require
RCD_SCRIPTS=		gkrellmd
CONF_FILES=		${PREFIX}/share/examples/gkrellm-server/gkrellmd.conf ${PREFIX}/etc/gkrellmd.conf

ALL_TARGET=		netbsd
INSTALL_TARGET=		install_netbsd

WRKSRC=			${WRKDIR}/gkrellm-${GKRELLM_VERSION}

pre-build:
	${SED} -e s,@@PREFIX@@,${PREFIX}, \
	    <${WRKSRC}/server/gkrellmd.h >${WRKSRC}/server/gkrellmd.h.sed
	${MV} ${WRKSRC}/server/gkrellmd.h.sed ${WRKSRC}/server/gkrellmd.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gkrellm-server
	${INSTALL_DATA} ${WRKSRC}/server/gkrellmd.conf ${PREFIX}/share/examples/gkrellm-server

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
