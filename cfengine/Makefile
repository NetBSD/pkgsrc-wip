# $NetBSD: Makefile,v 1.8 2006/04/25 20:04:35 ahallmann Exp $
# $Id: Makefile,v 1.8 2006/04/25 20:04:35 ahallmann Exp $

.include "Makefile.common"

PKG_OPTIONS_VAR=	PKG_OPTIONS.cfengine2
PKG_SUPPORTED_OPTIONS=	static cfengine-thread
PKG_SUGGESTED_OPTIONS=	static cfengine-thread

.include "../../mk/bsd.options.mk"

COMMENT=	Automate configuration and administration of large systems, networks

GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

BUILD_DEFS+=		USE_INET6

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4:Q}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}

RCD_SCRIPTS=		cfexecd cfservd cfenvd

# PR#33028
# Cfengine needs flex not lex.
# On netbsd flex=lex, so USE_TOOLS doesn't do anything.
# But other platforms i.e. Solaris need this.

USE_TOOLS+=		flex

.if (empty(PKG_OPTIONS:Mcfengine-pthread))
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
	${INSTALL_MAN_DIR} ${PREFIX:Q}/man/man8
	${INSTALL_MAN} ${WRKSRC:Q}/doc/*.8 ${PREFIX:Q}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/cfengine
	${INSTALL_DATA} ${WRKSRC:Q}/inputs/*.example \
		${PREFIX:Q}/share/examples/cfengine/
	${INSTALL_DATA_DIR:Q} ${VARBASE:Q}/cfengine/inputs

.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
