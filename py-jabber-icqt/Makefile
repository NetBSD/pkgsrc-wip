# $NetBSD: Makefile,v 1.32 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=		pyicqt-0.8.1.5
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME:S/py//}
CATEGORIES=		chat python
MASTER_SITES=		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/pyicqt/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
PYTHON_VERSIONS_ACCEPTED=	27 # py-imaging

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
SUBST_VARS.paths=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	TRANSPORTDIR
SUBST_VARS.paths+=	JABBER_SPOOLDIR
SUBST_VARS.paths+=	JABBER_TRANSDIR
SUBST_VARS.paths+=	JABBER_GROUP
SUBST_VARS.paths+=	JABBER_USER
SUBST_VARS.paths+=	JABBER_LOGDIR
SUBST_VARS.paths+=	PREFIX
SUBST_VARS.paths+=	JABBER_PIDDIR
SUBST_VARS.paths+=	PYTHONBIN

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
