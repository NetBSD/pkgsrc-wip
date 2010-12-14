# $NetBSD: Makefile,v 1.9 2010/12/14 17:13:07 noud4 Exp $
#

PKGNAME=		multisync-syncml-0.82
PKGREVISION=		4

COMMENT=		SyncML module for Multisync

CONFLICTS=		multisync-syncml-moto-[0-9]*

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/syncml_plugin/

DEPENDS+=		multisync>=0.82:../../wip/multisync
BUILD_DEPENDS+=		libtool-base>=1.5.10:../../devel/libtool-base
USE_TOOLS+=		aclocal autoconf autoheader automake

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
.include "../../wip/libwbxml2-patched/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
