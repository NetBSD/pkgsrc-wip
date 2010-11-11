# $NetBSD: Makefile,v 1.6 2010/11/11 22:42:07 shattered Exp $
#

DISTNAME=		mu-conference_0.8
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		chat
MASTER_SITES=		http://download.gna.org/mu-conference/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		https://gna.org/projects/mu-conference/
COMMENT=		Implementation of the JEP-0045 Multi-User Chat protocol

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src

USE_TOOLS+=		pkg-config

RCD_SCRIPTS=		muc

.include "../../wip/jabberd/transports.mk"
.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		JABBER_LOGDIR JABBER_PIDDIR
PKG_USERS_VARS+=	JABBER_USER

FILES_SUBST+=		JABBER_PIDDIR=${JABBER_PIDDIR:Q}
FILES_SUBST+=		JABBER_USER=${JABBER_USER:Q}

EGDIR=			${PREFIX}/${JABBER_EXDIR}
CONF_FILES+=		${EGDIR}/muc-default.xml ${PKG_SYSCONFDIR:Q}/muc.xml

DOCDIR=			${PREFIX}/share/doc/muc
DOCFILES=		ChangeLog README FAQ TODO XEP0045_SUPPORT

INSTALLATION_DIRS=	bin ${JABBER_EXDIR} share/doc/muc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/mu-conference ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC:Q}/../muc-default.xml \
						${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/../style.css \
						${DESTDIR}${EGDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC:Q}/../${f} ${DESTDIR}${DOCDIR}
.endfor


# clean up path info
SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	../muc-default.xml
SUBST_SED.paths+=	-e 's,@JABBER_SPOOLDIR@,${JABBER_SPOOLDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_LOGDIR@,${JABBER_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_PIDDIR@,${JABBER_PIDDIR},g'

.include "../../devel/libidn/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
