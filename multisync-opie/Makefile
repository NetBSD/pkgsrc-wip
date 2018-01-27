# $NetBSD: Makefile,v 1.7 2010/06/13 22:47:11 thomasklausner Exp $
#

PKGNAME=		multisync-opie-0.82
PKGREVISION=		4

COMMENT=		Module to sync Opie-devices with MultiSync

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/opie_sync/

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
.include "../../www/curl/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
