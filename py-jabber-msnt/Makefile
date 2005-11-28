# $NetBSD: Makefile,v 1.5 2005/11/28 00:27:27 rillig Exp $

DISTNAME=		pymsnt-0.10.2
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME:S/py//}
CATEGORIES=		chat python
MASTER_SITES=		http://msn-transport.jabberstudio.org/tarballs/

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://msn-transport.jabberstudio.org/
COMMENT=		Transport connecting Jabber to the MSN network

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
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
USE_PKGINSTALL=		yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	pymsnt

TRANSPORTDIR=		${JABBERD_TRANSDIR}/pymsnt

FILES_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PLIST_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}

.include "../../wip/jabberd/transports.mk"

CONF_FILES=	${EGDIR}/pymsnt.xml ${PKG_SYSCONFDIR}/pymsnt.xml

do-install:
	@ ${INSTALL_SCRIPT_DIR} ${PREFIX}/${TRANSPORTDIR}
	@ cd ${WRKSRC}/src && \
	for i in `find . \( \( -type f -name '*.orig' -o \
			-type d -name .svn \) -prune \) -o -type f -print` ;\
	do \
	    ${ECHO} "Installing $$i -> ${PREFIX}/${TRANSPORTDIR}/$$i";\
	    ${INSTALL_SCRIPT_DIR} `${DIRNAME} ${PREFIX}/${TRANSPORTDIR}/$$i` ;\
	    ${INSTALL_SCRIPT} $$i ${PREFIX}/${TRANSPORTDIR}/$$i ;\
	done
	@ cd ${WRKSRC}; \
	${INSTALL_SCRIPT} PyMSNt.tac ${PREFIX}/${TRANSPORTDIR}
	${INSTALL_DATA_DIR} ${EGDIR};\
	${INSTALL_DATA} ${WRKSRC}/config-example.xml ${EGDIR}/pymsnt.xml

SUBST_CLASSES=		paths
SUBST_MESSAGE.paths=	"Localizing Paths"
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	config-example.xml PyMSNt.tac
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g' \
			-e 's,@TRANSPORTDIR@,${TRANSPORTDIR},g' \
			-e 's,@JABBERD_SPOOLDIR@,${JABBERD_SPOOLDIR},g' \
			-e 's,@JABBERD_TRANSDIR@,${JABBERD_TRANSDIR},g' \
			-e 's,@JABBERD_GROUP@,${JABBERD_GROUP},g' \
			-e 's,@JABBERD_USER@,${JABBERD_USER},g' \
			-e 's,@JABBERD_LOGDIR@,${JABBERD_LOGDIR},g' \
			-e 's,@PREFIX@,${PREFIX},g' \
			-e 's,@JABBERD_PIDDIR@,${JABBERD_PIDDIR},g'

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
