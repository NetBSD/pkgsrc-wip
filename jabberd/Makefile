# $NetBSD: Makefile,v 1.1.1.1 2003/05/09 18:44:35 xtraeme Exp $
#

DISTNAME=	jabber-1.4.2
CATEGORIES=	net
MASTER_SITES=	http://jabberd.jabberstudio.org/downloads/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://jabberd.jabberstudio.org/downloads/
COMMENT=	Server messagging instant

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes

RCD_SCRIPTS=		jabber

EGDIR=			${PREFIX}/share/examples/jabberd
LIBDIR=			${PREFIX}/lib/jabberd
INCDIR=			${PREFIX}/include/jabberd
SPOOLDIR=		/var/spool/jabberd
LOGDIR=			/var/log/jabberd

CONF_FILES=	${EGDIR}/jabber.xml.conf.default ${PKG_SYSCONFDIR}/jabber.xml

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${SPOOLDIR}
	${INSTALL_DATA_DIR} ${LOGDIR}
	${INSTALL_DATA_DIR} ${LIBDIR}
	${INSTALL_DATA_DIR} ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabber.xml \
		${EGDIR}/jabber.xml.conf.default
	${INSTALL_PROGRAM} ${WRKSRC}/jabberd/jabberd \
		${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/jsm/jsm.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/xdb_file/xdb_file.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pthsock/pthsock_client.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dnsrv/dnsrv.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dialback/dialback.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/jabberd.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/lib/lib.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/lib/xmlparse.h ${INCDIR}

.include "../../devel/pth/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
