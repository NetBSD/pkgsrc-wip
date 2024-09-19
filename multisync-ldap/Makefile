# $NetBSD: Makefile,v 1.10 2012/11/13 20:28:39 othyro Exp $
#

PKGNAME=		multisync-ldap-0.82
PKGREVISION=		4

COMMENT=		LDAP module for Multisync
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/multisync-0.82/plugins/ldap_plugin/
DEPENDS+=		multisync>=0.82:../../wip/multisync
TOOL_DEPENDS+=		libtool-base>=1.5.10:../../devel/libtool-base
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
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
