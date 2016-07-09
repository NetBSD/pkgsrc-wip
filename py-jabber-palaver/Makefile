# $NetBSD: Makefile,v 1.11 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	palaver-0.6
PKGNAME=	${PYPKGPREFIX}-jabber-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	http://code.stanziq.com/cgit/palaver/palaver/snapshot/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://code.stanziq.com/palaver
COMMENT=	XEP-0045 + XEP-0128 Multi-User Conferencing package
LICENSE=	mit
BROKEN=		Distfile has disappeared.

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted>=8.1.0:../../net/py-twisted
# DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

# it's a python package using the standard Python packager
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-twisted

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"


JABBER_USER?=		jabberd
JABBER_GROUP?=		jabberd
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PKG_USERS_VARS=		JABBER_USER
PKG_GROUPS_VARS=	JABBER_GROUP

.include "../../wip/jabberd/transports.mk"

DOCDIR=			${DESTDIR}${PREFIX}/share/doc/palaver
DOCFILES=		README.txt XEP.txt db/muc-pgsql.sql

INSTALLATION_DIRS=	share/doc/palaver

CONF_FILES=	${EGDIR}/palaver.xml ${PKG_SYSCONFDIR}/palaver.xml

RCD_SCRIPTS=	palaver

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example-config.xml \
						${DESTDIR}${EGDIR}/palaver.xml

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	example-config.xml
SUBST_SED.paths+=	-e 's,@JABBER_GROUP@,${JABBER_GROUP},g'
SUBST_SED.paths+=	-e 's,@JABBER_LOGDIR@,${JABBER_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_PIDDIR@,${JABBER_PIDDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_SPOOLDIR@,${JABBER_SPOOLDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_TRANSDIR@,${JABBER_TRANSDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_USER@,${JABBER_USER},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@TRANSPORTDIR@,${TRANSPORTDIR},g'

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
