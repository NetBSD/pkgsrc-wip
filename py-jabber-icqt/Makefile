# $NetBSD: Makefile,v 1.32 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=		pyicqt-0.8.1.5
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME:S/py//}
CATEGORIES=		chat python
MASTER_SITES=		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/pyicqt/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://code.google.com/p/pyicqt/
COMMENT=		Transport connecting Jabber to the ICQ IM network
LICENSE=		gnu-gpl-v2

CONFLICTS=		${PYPKGPREFIX}-jabber-pyicq-t-*

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted>=8.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1.5:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6nb1:../../security/py-OpenSSL

# Fifth paragraph - all build definitions that describe things used by
# the package.  These include: WRKSRC, GNU_CONFIGURE,
# HAS_CONFIGURE, USE_PKGLOCALEDIR, USE_INSTALL, TEXINFO_REQD, USE_JAVA,
# USE_PERL5, INFO_FILES, DIST_SUBDIR, etc.
# EXTRACT_ONLY=		# yes
NO_BUILD=		yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	pyicqt

REPLACE_PYTHON+=		PyICQt.py
REPLACE_PYTHON+=		tools/infodump.py
REPLACE_PYTHON+=		tools/managessi.py
REPLACE_PYTHON+=		tools/migrate.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-imaging

TRANSPORTDIR=		${JABBER_TRANSDIR}/pyicqt

FILES_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN}
PLIST_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}

#INSTALLATION_DIRS+=	${TRANSPORTDIR}

.include "../../wip/jabberd/transports.mk"

CONF_FILES=	${EGDIR}/pyicqt.xml ${PKG_SYSCONFDIR}/pyicqt.xml

do-install:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/${TRANSPORTDIR}
	cd ${WRKSRC} && \
	for i in `find src data tools \\( \\( -type f -name '*.orig' -o \
			-type f -name '*.orig_dist' -o \
			-type d -name .svn \\) -prune \\) -o -type f -print` ;\
	do \
	    ${ECHO} "Installing $$i -> " \
				    "${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i";\
	    ${INSTALL_SCRIPT_DIR} \
			`${DIRNAME} ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i` ;\
	    ${INSTALL_SCRIPT} $$i ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i ;\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/PyICQt.py ${DESTDIR}${PREFIX}/bin/PyICQt
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/config_example.xml \
						${DESTDIR}${EGDIR}/pyicqt.xml

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	config_example.xml PyICQt.py src/main.py
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@TRANSPORTDIR@,${TRANSPORTDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_SPOOLDIR@,${JABBER_SPOOLDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_TRANSDIR@,${JABBER_TRANSDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_GROUP@,${JABBER_GROUP},g'
SUBST_SED.paths+=	-e 's,@JABBER_USER@,${JABBER_USER},g'
SUBST_SED.paths+=	-e 's,@JABBER_LOGDIR@,${JABBER_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@JABBER_PIDDIR@,${JABBER_PIDDIR},g'
SUBST_SED.paths+=	-e 's,@PYTHONBIN@,${PYTHONBIN},g'

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
