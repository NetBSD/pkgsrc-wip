# $NetBSD: Makefile,v 1.2 2006/04/19 11:14:38 ahallmann Exp $
#

.include "Makefile.common"

PKG_OPTIONS_VAR+=       PKG_OPTIONS.cfengine2
PKG_SUPPORTED_OPTIONS=  nopthread static
.include "../../mk/bsd.options.mk"

COMMENT=	Automate configuration and administration of large systems

GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

BUILD_DEFS+=		USE_INET6

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

RCD_SCRIPTS=		cfexecd cfservd cfenvd

.if (!empty(PKG_OPTIONS:Mnopthread))
CONFIGURE_ARGS+= --without-pthreads
.else
PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.endif

#
# static linking should be prefered for cfengine 
# as it likes to distribute itself as a binary
# for boot-straping.
#
.if (!empty(PKG_OPTIONS:Mstatic))
LDFLAGS+= -static
BUILDLINK_DEPMETHOD.db4=build
BUILDLINK_DEPMETHOD.openssl=build
.endif

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cfengine
	${INSTALL_DATA} ${WRKSRC}/inputs/*.example \
		${PREFIX}/share/examples/cfengine/
	${INSTALL_DATA_DIR} /var/cfengine/inputs

.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
