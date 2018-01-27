# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	punjab-0.13
PKGNAME=	${PYPKGPREFIX}-jabber-${DISTNAME}
CATEGORIES=	chat python
# MASTER_SITES=	http://code.stanziq.com/punjab/browser/releases/
# MASTER_SITES=	http://code.stanziq.com/punjab/export/38/releases/
# MASTER_SITES=	http://code.stanziq.com/cgit/punjab/punjab/snapshot/
MASTER_SITES=	https://github.com/twonds/punjab/archive/master.zip


MAINTAINER=	eric@cirr.com
HOMEPAGE=	https://github.com/twonds/punjab
COMMENT=	HTTP XMMP client interface implementing BOSH/XEP-0124
BROKEN=		Source tarballs have disappeared.

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted>=8.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.0.1:../../security/py-crypto

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

JABBER_USER?=		jabberd
JABBER_GROUP?=		jabberd
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PKG_USERS_VARS+=	JABBER_USER
PKG_GROUPS_VARS+=	JABBER_GROUP

.include "../../wip/jabberd/transports.mk"

DOCDIR=			${PREFIX}/share/doc/punjab
DOCFILES=		README.txt INSTALL.txt

INSTALLATION_DIRS=	share/doc/punjab

RCD_SCRIPTS=	punjab

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${EGDIR}

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

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
