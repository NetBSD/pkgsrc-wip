# $NetBSD: Makefile,v 1.7 2003/05/10 10:08:22 xtraeme Exp $
#

DISTNAME=	jabber-1.4.2
CATEGORIES=	net
MASTER_SITES=	http://jabberd.jabberstudio.org/downloads/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://jabberd.jabberstudio.org/downloads/
COMMENT=	Instant messaging server

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--enable-ssl

RCD_SCRIPTS=		jabber

EGDIR=			${PREFIX}/share/examples/jabberd
LIBDIR=			${PREFIX}/lib/jabberd
INCDIR=			${PREFIX}/include/jabberd
OWN_DIRS=		/var/spool/jabberd
OWN_DIRS+=		/var/log/jabberd

CONF_FILES=	${EGDIR}/jabber.xml ${PKG_SYSCONFDIR}/jabber.xml

post-extract:
	${MV} ${WRKSRC}/jabber.xml ${WRKSRC}/jabber.xml.in

pre-configure:
	${SED} -e "s|@LIBDIR@|${PREFIX}/lib/jabberd|g" \
		-e "s|@LOG_DIR@|/var/log/jabberd|g" \
		-e "s|@PID_DIR@|/var/run|g" \
		< ${WRKSRC}/jabber.xml.in > ${WRKSRC}/jabber.xml

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${LIBDIR}
	${INSTALL_DATA_DIR} ${INCDIR}
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

.include "../../security/openssl/buildlink2.mk"
.include "../../devel/pth/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
