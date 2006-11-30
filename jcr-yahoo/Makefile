# $NetBSD: Makefile,v 1.11 2006/11/30 06:01:49 schnoebe Exp $
#

DISTNAME=		yahoo-transport-2.3.2
PKGNAME=		jcr-yahoo-2.3.2
CATEGORIES=		chat
MASTER_SITES=		http://jabber.terrapin.com/JCR/ http://www.jabberstudio.org/projects/yahoo-transport/releases/download.php?file=
DISTFILES=		${DISTNAME}.tar.gz jcr-0.2.4.tar.gz

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://jabber.terrapin.com/JCR/
COMMENT=		Yahoo IM gateway for Jabber/XMPP servers

DEPENDS+=		jabberd-[0-9]*:../../chat/jabberd2

WRKSRC=			${WRKDIR}/jcr-0.2.4
SUBWRKSRC=		${WRKSRC}/${DISTNAME}
XMLCONFIG=		${WRKDIR}/${DISTNAME}/yahoo-jcr.xml

USE_TOOLS+=		gmake pkg-config

PKG_SYSCONFSUBDIR=	jabberd
RCD_SCRIPTS=		yahoo

BUILD_DEFS+=		JABBERD_USER JABBERD_LOGDIR JABBERD_PIDDIR
JABBERD_USER?=		jabberd

FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR:Q}
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER:Q}

EGDIR=			${PREFIX}/share/examples/jabberd
CONF_FILES+=		${EGDIR}/yahoo-jcr.xml ${PKG_SYSCONFDIR}/yahoo-jcr.xml

post-extract:
	mv ${XMLCONFIG} ${XMLCONFIG}.in

pre-patch:
	cd ${WRKDIR} ; pax -rw -pp ${DISTNAME} ${WRKSRC}

pre-configure:
	sed	-e "s|\(<logdir>\)[^<]*|\1${JABBERD_LOGDIR}|g" \
		-e "s|\(<pidfile>\).|\1${JABBERD_PIDDIR}|g" \
		-e "s|\(<spool>\).|\1${JABBERD_SPOOLDIR}|g" \
		${XMLCONFIG}.in > ${XMLCONFIG}

post-build:
	# ${CP} ${WRKSRC}/src/main.c ${WRKSRC}/src/jcomp.mk ${SUBWRKSRC}
	cd ${SUBWRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -f jcomp.mk

do-install:
	${INSTALL_PROGRAM} ${SUBWRKSRC}/yahoo-transport ${PREFIX}/bin
	${INSTALL_DATA} ${XMLCONFIG} ${EGDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

