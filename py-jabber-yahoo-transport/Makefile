# $NetBSD: Makefile,v 1.3 2006/12/20 01:06:57 schnoebe Exp $

DISTNAME=		yahoo-transport-0.3
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME}
CATEGORIES=		chat python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmpppy/}

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://xmpppy.sourceforge.net/
COMMENT=		Transport connecting Jabber to the AOL IM network

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-expat>=0nb4:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-xmpppy>=0.3.1:../../wip/py-xmpppy
DEPENDS+=	${PYPKGPREFIX}-dns>=1.3.3:../../net/py-dns

# Fifth paragraph - all build definitions that describe things used by
# the package.  These include: WRKSRC, GNU_CONFIGURE,
# HAS_CONFIGURE, USE_PKGLOCALEDIR, USE_INSTALL, TEXINFO_REQD, USE_JAVA,
# USE_PERL5, INFO_FILES, DIST_SUBDIR, etc.
# EXTRACT_ONLY=		# yes
NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS+=	yahoo.py

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	yahoo-transport

TRANSPORTDIR=		${JABBER_TRANSDIR}/yahoo

FILES_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PLIST_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}

.include "../../wip/jabberd/transports.mk"

CONF_FILES=	${EGDIR}/yahoo-transport.ini ${PKG_SYSCONFDIR}/yahoo-transport.ini

do-install:
	@ ${INSTALL_SCRIPT_DIR} ${PREFIX}/${TRANSPORTDIR}
	@ cd ${WRKSRC} && \
	for i in `find . \\( \\( -type f -name '*.orig' -o \
		    -type d -name CVS -o \
		    -type d -name .svn \\) -prune \\) -o -type f -print` ;\
	do \
	    ${ECHO} "Installing $$i -> ${PREFIX}/${TRANSPORTDIR}/$$i";\
	    ${INSTALL_SCRIPT_DIR} `${DIRNAME} ${PREFIX}/${TRANSPORTDIR}/$$i` ;\
	    ${INSTALL_SCRIPT} $$i ${PREFIX}/${TRANSPORTDIR}/$$i ;\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/transport.ini ${EGDIR}/yahoo-transport.ini

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	transport.ini
SUBST_FILES.paths+=	yahoo.py
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
