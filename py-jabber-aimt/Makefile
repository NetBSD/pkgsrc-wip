# $NetBSD: Makefile,v 1.20 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=		pyaim-t-0.8a
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME:S/py//}
PKGREVISION=		1
CATEGORIES=		chat python
MASTER_SITES=		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/pyaimt/
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
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
PYTHON_VERSIONS_ACCEPTED=	27 # py-imaging

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
