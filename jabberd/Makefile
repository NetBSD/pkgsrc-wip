# $NetBSD: Makefile,v 1.20 2003/10/06 14:11:41 tvierling Exp $
#

DISTNAME=		jabber-1.4.2
PKGNAME=		${DISTNAME:S/-/d-/}
CATEGORIES=		net
MASTER_SITES=		http://jabberd.jabberstudio.org/1.4/dist/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://jabberd.jabberstudio.org/1.4/
COMMENT=		Instant messaging server

CONFLICTS=		jabberd2-[0-9]*:../../wip/jabberd2

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--enable-ssl

RCD_SCRIPTS=		jabberd

EGDIR=			${PREFIX}/share/examples/jabberd
LIBDIR=			${PREFIX}/lib/jabberd
INCDIR=			${PREFIX}/include/jabberd

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		JABBERD_USER JABBERD_GROUP \
			JABBERD_LOGDIR	JABBERD_SPOOLDIR \
			JABBERD_PIDDIR

JABBERD_USER?=		jabberd
JABBERD_GROUP?=		jabberd
PKG_GROUPS=             ${JABBERD_GROUP}
PKG_USERS=              ${JABBERD_USER}:${JABBERD_GROUP}::Jabberd\\ user

JABBERD_LOGDIR?=	/var/log/jabberd
JABBERD_SPOOLDIR?=	/var/spool/jabberd
JABBERD_PIDDIR?=	/var/run/jabberd

.for f in ${JABBERD_LOGDIR} ${JABBERD_SPOOLDIR} ${JABBERD_PIDDIR}
OWN_DIRS_PERMS+=	${f} ${JABBERD_USER} ${JABBERD_GROUP} 750
.endfor

CONF_FILES=		${EGDIR}/jabber.xml ${PKG_SYSCONFDIR}/jabber.xml

post-extract:
	${MV} ${WRKSRC}/jabber.xml ${WRKSRC}/jabber.xml.in

pre-configure:
	${SED}	\
		-e "s|@LIBDIR@|${PREFIX}/lib/jabberd|g" \
		-e "s|@LOG_DIR@|${JABBERD_LOGDIR}|g" \
		-e "s|@PID_DIR@|${JABBERD_PIDDIR}|g" \
		-e "s|@SPOOLDIR@|${JABBERD_SPOOLDIR}|g" \
		< ${WRKSRC}/jabber.xml.in > ${WRKSRC}/jabber.xml

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${LIBDIR} ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabber.xml ${EGDIR}/jabber.xml
	${INSTALL_PROGRAM} ${WRKSRC}/jabberd/jabberd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/jsm/jsm.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/xdb_file/xdb_file.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pthsock/pthsock_client.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dnsrv/dnsrv.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dialback/dialback.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/jabberd.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/lib/lib.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/lib/xmlparse.h ${INCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/platform-settings ${PKG_SYSCONFDIR}

post-deinstall:
	${RM} ${PKG_SYSCONFDIR}/platform-settings

.include "../../devel/pth/buildlink2.mk" # uses pth.h, not pthread.h
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
