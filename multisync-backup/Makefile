# $NetBSD: Makefile,v 1.1 2005/01/05 13:09:45 mreriksson Exp $
#

PKGNAME=		multisync-backup-0.82

COMMENT=		Module for Multisync to backup your PIM data

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/backup_plugin/

DEPENDS+=		multisync>=0.82:../../wip/multisync

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
