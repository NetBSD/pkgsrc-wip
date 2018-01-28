# $NetBSD: Makefile,v 1.20 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=		pyaim-t-0.8a
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME:S/py//}
PKGREVISION=		1
CATEGORIES=		chat python
MASTER_SITES=		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/pyaimt/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://code.google.com/p/pyaimt/
COMMENT=		Transport connecting Jabber to the AOL IM network

# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6nb1:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-twisted>=8.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1.5:../../graphics/py-imaging

# Fifth paragraph - all build definitions that describe things used by
# the package.  These include: WRKSRC, GNU_CONFIGURE,
# HAS_CONFIGURE, USE_PKGLOCALEDIR, USE_INSTALL, TEXINFO_REQD, USE_JAVA,
# USE_PERL5, INFO_FILES, DIST_SUBDIR, etc.
# EXTRACT_ONLY=		# yes
NO_BUILD=			yes
REPLACE_PYTHON+=		PyAIMt.py
REPLACE_PYTHON+=		tools/infodump.py
REPLACE_PYTHON+=		tools/managessi.py
REPLACE_PYTHON+=		tools/migrate.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-imaging

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	pyaimt

TRANSPORTDIR=		${JABBER_TRANSDIR}/pyaimt

FILES_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PLIST_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}

.include "../../wip/jabberd/transports.mk"

CONF_FILES=	${EGDIR}/pyaimt.xml ${PKG_SYSCONFDIR}/pyaimt.xml

do-install:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/${TRANSPORTDIR}
	cd ${WRKSRC} && \
	for i in `find src data tools \\( \\( -type f -name '*.orig' -o \
		    -type d -name .svn \\) -prune \\) -o -type f -print` ;\
	do \
	    ${ECHO} "Installing $$i -> " \
				"${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i";\
	    ${INSTALL_SCRIPT_DIR} \
		` ${DIRNAME} ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i ` ;\
	    ${INSTALL_SCRIPT} $$i ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i ;\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && \
	    ${INSTALL_SCRIPT} PyAIMt.py ${DESTDIR}${PREFIX}/bin/PyAIMt
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/config_example.xml \
						${DESTDIR}${EGDIR}/pyaimt.xml

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	config_example.xml
SUBST_FILES.paths+=	src/langs/__init__.py
SUBST_FILES.paths+=	PyAIMt.py
SUBST_FILES.paths+=	src/main.py
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@TRANSPORTDIR@,${TRANSPORTDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_SPOOLDIR@,${JABBER_SPOOLDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_TRANSDIR@,${JABBER_TRANSDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_GROUP@,${JABBER_GROUP},g'
SUBST_SED.paths+=	-e 's,@JABBER_USER@,${JABBER_USER},g'
SUBST_SED.paths+=	-e 's,@JABBER_LOGDIR@,${JABBER_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@JABBER_PIDDIR@,${JABBER_PIDDIR},g'

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
