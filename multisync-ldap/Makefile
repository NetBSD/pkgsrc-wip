# $NetBSD: Makefile,v 1.1 2005/01/09 09:30:29 mreriksson Exp $
#

PKGNAME=		multisync-ldap-0.82

COMMENT=		LDAP module for Multisync

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/ldap_plugin/

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
.include "../../databases/openldap/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
