# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:48 shattered Exp $
#

PKGNAME=		multisync-palm-0.82

COMMENT=		Module for synchronization with Palm devices

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/palm_sync/

DEPENDS+=		multisync>=0.82:../../wip/multisync

BUILD_DEPENDS+=		libtool-base>=1.5.10:../../devel/libtool-base

pre-configure:
	cd work/multisync-${PKGVERSION} && \
		${ACLOCAL} && \
		${AUTOHEADER} && \
		${AUTOCONF} && \
		${AUTOMAKE} -acf
	cd ${WRKSRC} && \
		${ACLOCAL} && \
		${PREFIX}/bin/libtoolize --force --copy && \
		${AUTOHEADER} && \
		${AUTOCONF} && \
		${AUTOMAKE} -acf
	cd work/multisync-${PKGVERSION} && \
		./configure ${CONFIGURE_ENV} ${CONFIGURE_ARGS}

do-install:
	cd ${WRKSRC} && \
		${MAKE} install

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
