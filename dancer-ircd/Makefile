# $NetBSD: Makefile,v 1.13 2003/06/22 10:38:09 cjep Exp $
#

DISTNAME=	dancer-ircd-1.0.31+maint8-fn6
PKGNAME=	${DISTNAME:S/+maint8-fn6/m8/}
CATEGORIES=	chat
MASTER_SITES=	http://freenode.net/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://freenode.net/dancer_ircd.shtml
COMMENT=	Irc daemon based on hybrid ircd

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--with-config=dist

EGDIR=          ${PREFIX}/share/examples/dancer-ircd
DOCDIR=		${PREFIX}/share/doc/dancer-ircd

OWN_DIRS=	/var/lib/dancer-ircd
OWN_DIRS+=	/var/log/dancer-ircd

RCD_SCRIPTS=		dancer-ircd
PKG_SYSCONFSUBDIR=	dancer-ircd

CONF_FILES=	${EGDIR}/ircd.conf.default ${PKG_SYSCONFDIR}/ircd.conf

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	DANCER_IRCD_NETWORK_NAME DANCER_IRCD_NETWORK_DESCR \
		DANCER_IRCD_REALNAME DANCER_IRCD_LOGDIR \
		DANCER_IRCD_PIDDIR DANCER_IRCD_CONFDIR

# Default targets

DANCER_IRCD_NETWORK_NAME?=	"My\ network"
DANCER_IRCD_NETWORK_DESCR?=	"A\ happy\ and\ sweet\ network"
DANCER_IRCD_REALNAME?=		"my_ircd.com"
DANCER_IRCD_LOGDIR?=		/var/log/dancer-ircd
DANCER_IRCD_PIDDIR?=		/var/run
DANCER_IRCD_CONFDIR?=		${PKG_SYSCONFDIR}

post-extract:
	${MV} ${WRKSRC}/include/config.h.dist ${WRKSRC}/include/config.h.dist.in

pre-configure:
	${SED} -e "s|@SPATH@|${PREFIX}/sbin/dancer-ircd|g" \
		-e "s|@CPATH@|${DANCER_IRCD_CONFDIR}/dancer-ircd|g" \
	        -e "s|@KPATH@|${DANCER_IRCD_CONFDIR}/kline.conf|g" \
		-e "s|@DLPATH@|${DANCER_IRCD_CONFDIR}/dline.conf|g" \
		-e "s|@MPATH@|${DANCER_IRCD_CONFDIR}/motd|g" \
		-e "s|@LPATH@|${DANCER_IRCD_LOGDIR}/ircd.log|g" \
		-e "s|@PPATH@|${DANCER_IRCD_PIDDIR}/dancer-ircd.pid|g" \
		-e "s|@HPATH@|${DANCER_IRCD_CONFDIR}/ohelp|g" \
		-e "s|@OPATH@|${DANCER_IRCD_CONFDIR}/omotd|g" \
		-e "s|@MXPATH@|${DANCER_IRCD_CONFDIR}/ircd.max|g" \
		-e "s|@NET_NAME@|${DANCER_IRCD_NETWORK_NAME}|g" \
		-e "s|@NET_DESCR@|${DANCER_IRCD_NETWORK_DESCR}|g" \
		-e "s|@NET_RNAME@|${DANCER_IRCD_REALNAME}|g" \
		< ${WRKSRC}/include/config.h.dist.in > \
		${WRKSRC}/include/config.h.dist

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${DOCDIR} ${DOCDIR}/hybrid
	( cd ${WRKSRC}/doc && \
		for f in RE* *.txt; do ${INSTALL_DATA} $$f ${DOCDIR}; done )
	( cd ${WRKSRC}/doc/hybrid/ && \
		for f in *; do ${INSTALL_DATA} $$f ${DOCDIR}/hybrid; done )
	${INSTALL_PROGRAM} ${WRKSRC}/src/dancer-ircd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkconf ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/install_ircd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/viconf ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkpasswd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${EGDIR}/ircd.conf.default

.include "../../mk/bsd.pkg.mk"
