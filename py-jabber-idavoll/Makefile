# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	idavoll-0.9.1
PKGNAME=	${PYPKGPREFIX}-jabber-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	http://idavoll.ik.nu/releases/0.9.1/
LICENSE=	mit

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://idavoll.ik.nu/
HOMEPAGE=	https://github.com/ralphm/idavoll
COMMENT=	XMPP publish-subscribe (XEP-0060) component (via twisted)

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted>=8.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.0.1:../../security/py-crypto
# wonkle

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"


JABBER_USER?=		jabberd
JABBER_GROUP?=		jabberd
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PKG_USERS_VARS+=	JABBER_USER
PKG_GROUPS_VARS+=	JABBER_GROUP

.include "../../wip/jabberd/transports.mk"

DOCDIR=			${PREFIX}/share/doc/idavoll
DOCFILES=		README INSTALL NEWS LICENSE

INSTALLATION_DIRS=	share/doc/idavoll

RCD_SCRIPTS=	idavoll

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	example-config.xml
SUBST_VARS.paths=	JABBER_GROUP
SUBST_VARS.paths+=	JABBER_LOGDIR
SUBST_VARS.paths+=	JABBER_PIDDIR
SUBST_VARS.paths+=	JABBER_SPOOLDIR
SUBST_VARS.paths+=	JABBER_TRANSDIR
SUBST_VARS.paths+=	JABBER_USER
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	PREFIX
SUBST_VARS.paths+=	TRANSPORTDIR

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
