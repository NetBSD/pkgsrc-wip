# $NetBSD: Makefile,v 1.1.1.1 2010/12/13 17:50:15 noud4 Exp $
#

PKGNAME=		multisync-syncml-moto-0.82

COMMENT=		SyncML module for Multisync (Motorola EZX)

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/syncml_plugin/

CONFLICTS=		multisync-syncml-[0-9]*

DEPENDS+=		multisync>=0.82:../../wip/multisync
BUILD_DEPENDS+=		libtool-base>=1.5.10:../../devel/libtool-base
USE_TOOLS+=		aclocal autoconf autoheader automake

PATCH_SITES=		http://www.troodon.org/a780/files/syncml/
PATCHFILES=		syncml_plugin_a780.patch
PATCH_DIST_STRIP=	-p3

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
.include "../../textproc/wbxml2/buildlink3.mk"	# wip/libwbxml2-patched
.include "../../wip/multisync/Makefile.common"
