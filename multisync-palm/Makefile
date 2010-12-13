# $NetBSD: Makefile,v 1.7 2010/12/13 18:07:14 noud4 Exp $
#

PKGNAME=		multisync-palm-0.82
PKGREVISION=		4

COMMENT=		Module for synchronization with Palm devices

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/palm_sync/

DEPENDS+=		multisync>=0.82:../../wip/multisync

BUILD_DEPENDS+=		libtool-base>=1.5.10:../../devel/libtool-base

pre-configure:
	cd ${WRKSRC}/../.. && \
		aclocal && \
		autoheader && \
		autoconf && \
		automake -acf
	cd ${WRKSRC} && \
		aclocal && \
		${PREFIX}/bin/libtoolize --force --copy && \
		autoheader && \
		autoconf && \
		automake -acf
	cd ${WRKSRC}/../.. && \
		./configure ${CONFIGURE_ENV} ${CONFIGURE_ARGS}

do-install:
	cd ${WRKSRC} && \
		${MAKE} install

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
