# $NetBSD: Makefile,v 1.5 2006/04/15 04:10:02 schnoebe Exp $

DISTNAME=		pyaim-t-0.7c
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME:S/py//}
CATEGORIES=		chat python
MASTER_SITES=		http://www.blathersource.org/download.php/pyaim-t/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://pyaim-t.blathersource.org/
COMMENT=		Transport connecting Jabber to the AOL IM network

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted>=2.1.0:../../wip/py-twisted
DEPENDS+=	${PYPKGPREFIX}-twisted-words>=0.1.0:../../wip/py-twisted-words
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=0.1.0:../../wip/py-twisted-web
DEPENDS+=	${PYPKGPREFIX}-twisted-xish>=0.1.0:../../wip/py-twisted-xish
DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1.5:../../graphics/py-imaging

# Fifth paragraph - all build definitions that describe things used by
# the package.  These include: WRKSRC, GNU_CONFIGURE,
# HAS_CONFIGURE, USE_PKGLOCALEDIR, USE_INSTALL, TEXINFO_REQD, USE_JAVA,
# USE_PERL5, INFO_FILES, DIST_SUBDIR, etc.
# EXTRACT_ONLY=		# yes
NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS+=	PyAIMt.py

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	pyaimt

TRANSPORTDIR=		${JABBERD_TRANSDIR}/pyaimt

FILES_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PLIST_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}

.include "../../wip/jabberd/transports.mk"

CONF_FILES=	${EGDIR}/pyaimt.xml ${PKG_SYSCONFDIR}/pyaimt.xml

do-install:
	@ ${INSTALL_SCRIPT_DIR} ${PREFIX}/${TRANSPORTDIR}
	@ cd ${WRKSRC} && \
	for i in `find src data tools \\( \\( -type f -name '*.orig' -o \
		    -type d -name .svn \\) -prune \\) -o -type f -print` ;\
	do \
	    ${ECHO} "Installing $$i -> ${PREFIX}/${TRANSPORTDIR}/$$i";\
	    ${INSTALL_SCRIPT_DIR} `${DIRNAME} ${PREFIX}/${TRANSPORTDIR}/$$i` ;\
	    ${INSTALL_SCRIPT} $$i ${PREFIX}/${TRANSPORTDIR}/$$i ;\
	done
	@ cd ${WRKSRC} && \
	    ${INSTALL_SCRIPT} PyAIMt.py ${PREFIX}/bin/PyAIMt
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/config_example.xml ${EGDIR}/pyaimt.xml

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	config_example.xml
SUBST_FILES.paths+=	src/langs/__init__.py
SUBST_FILES.paths+=	PyAIMt.py
SUBST_FILES.paths+=	src/main.py
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@TRANSPORTDIR@,${TRANSPORTDIR},g'
SUBST_SED.paths+=	-e 's,@JABBERD_SPOOLDIR@,${JABBERD_SPOOLDIR},g'
SUBST_SED.paths+=	-e 's,@JABBERD_TRANSDIR@,${JABBERD_TRANSDIR},g'
SUBST_SED.paths+=	-e 's,@JABBERD_GROUP@,${JABBERD_GROUP},g'
SUBST_SED.paths+=	-e 's,@JABBERD_USER@,${JABBERD_USER},g'
SUBST_SED.paths+=	-e 's,@JABBERD_LOGDIR@,${JABBERD_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@JABBERD_PIDDIR@,${JABBERD_PIDDIR},g'

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
