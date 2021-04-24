# $NetBSD: Makefile,v 1.14 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=		yahoo-transport-0.4.90
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME}
CATEGORIES=		chat python
#MASTER_SITES=		ftp://ftp.cirr.com/pub/eric/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xmpppy.sourceforge.net/
COMMENT=		Transport connecting Jabber to the Yahoo! IM network
LICENSE=		gnu-gpl-v2

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-expat>=0nb4:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-xmpppy>=0.4.1:../../chat/py-xmpppy

PYTHON_VERSIONS_ACCEPTED=	27 # py-xmpppy

# Fifth paragraph - all build definitions that describe things used by
# the package.  These include: WRKSRC, GNU_CONFIGURE,
# HAS_CONFIGURE, USE_PKGLOCALEDIR, USE_INSTALL, TEXINFO_REQD, USE_JAVA,
# USE_PERL5, INFO_FILES, DIST_SUBDIR, etc.
REPLACE_PYTHON+=	yahoo.py

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	yahoo-transport

TRANSPORTDIR=		${JABBER_TRANSDIR}/yahoo

FILES_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PLIST_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}

.include "../../wip/jabberd/transports.mk"

CONF_FILES=	${EGDIR}/yahoo-transport.xml ${PKG_SYSCONFDIR}/yahoo-transport.xml

INSTALLATION_DIRS+=	${TRANSPORTDIR}

do-build:

do-install:
	cd ${WRKSRC} && \
	for i in `find . -type f -name '*.py' -print` ; do \
	    ${ECHO} "Installing $$i -> " \
				"${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i";\
	    ${INSTALL_SCRIPT_DIR} \
			`${DIRNAME} ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i`;\
	    ${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i;\
	    ${ECHO} "Compiling ${PREFIX}/${TRANSPORTDIR}/$$i.";\
	    ${PYTHONBIN} -m py_compile ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i;\
	done ;\
	${INSTALL_DATA} ChangeLog ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/ ;\
	${INSTALL_SCRIPT} yahoo.py ${DESTDIR}${PREFIX}/${TRANSPORTDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/config_example.xml \
					${DESTDIR}${EGDIR}/yahoo-transport.xml

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	config_example.xml
SUBST_FILES.paths+=	config.py
SUBST_VARS.paths=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	TRANSPORTDIR
SUBST_VARS.paths+=	JABBER_SPOOLDIR
SUBST_VARS.paths+=	JABBER_TRANSDIR
SUBST_VARS.paths+=	JABBER_GROUP
SUBST_VARS.paths+=	JABBER_USER
SUBST_VARS.paths+=	JABBER_LOGDIR
SUBST_VARS.paths+=	PREFIX
SUBST_VARS.paths+=	JABBER_PIDDIR

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
