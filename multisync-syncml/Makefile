# $NetBSD: Makefile,v 1.2 2005/01/05 16:53:20 mreriksson Exp $
#

PKGNAME=		multisync-syncml-0.82

COMMENT=		SyncML module for Multisync

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/syncml_plugin/

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
.include "../../wip/multisync/Makefile.common"
