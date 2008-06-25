# $NetBSD: Makefile,v 1.1.1.1 2008/06/25 04:27:59 schnoebe Exp $
#

DISTNAME=		mu-conference_0.7
PKGNAME=		${DISTNAME:S/_/-/}
# PKGREVISION=		6
CATEGORIES=		chat
MASTER_SITES=		http://download.gna.org/mu-conference/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://gna.org/projects/mu-conference/
COMMENT=		Implementation of the JEP-0045 Multi-User Chat protocol

# DEPENDS+=		jabberd-[0-9]*:../../chat/jabberd2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src

# USE_TOOLS+=		gmake pax pkg-config
USE_TOOLS+=		pkg-config

PKG_SYSCONFSUBDIR=	jabberd
RCD_SCRIPTS=		muc

.include "../../wip/jabberd/transports.mk"
.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		JABBERD_LOGDIR JABBERD_PIDDIR
JABBERD_USER?=		jabberd
PKG_USERS_VARS+=	JABBERD_USER

FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR:Q}
FILES_SUBST+=		JABBERD_USER=${JABBERD_USER:Q}

EGDIR=			${PREFIX}/share/examples/jabberd
CONF_FILES+=		${EGDIR}/muc-jcr.xml ${PKG_SYSCONFDIR:Q}/muc-jcr.xml

INSTALLATION_DIRS=	bin share/examples/jabberd

# post-extract:
# 	@${MV} ${XMLCONFIG:Q} ${XMLCONFIG:Q}.in

# pre-configure:
# 	@${SED}	-e 's|\(<logdir>\)[^<]*|\1${JABBERD_LOGDIR}|g' \
# 		-e 's|\(<pidfile>\).|\1${JABBERD_PIDDIR}|g' \
# 		-e 's|\(<spool>\).|\1${JABBERD_SPOOLDIR}|g' \
# 		${XMLCONFIG:Q}.in > ${XMLCONFIG:Q}

# pre-build:
# 	cd ${WRKDIR:Q} && pax -rw -pe ${DISTNAME:Q} ${WRKSRC:Q}

# post-build:
# 	${CP} ${WRKSRC:Q}/src/main.c ${WRKSRC:Q}/src/jcomp.mk ${SUBWRKSRC:Q}
# 	cd ${SUBWRKSRC:Q} && ${SETENV} ${MAKE_ENV} ${GMAKE} -f jcomp.mk

# do-install:
# 	${INSTALL_PROGRAM} ${SUBWRKSRC:Q}/mu-conference ${DESTDIR}${PREFIX}/bin
# 	${INSTALL_DATA} ${WRKSRC:Q}/${DISTNAME:Q}/muc-jcr.xml ${DESTDIR}${EGDIR}

.include "../../devel/libidn/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
