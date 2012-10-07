# $NetBSD: Makefile,v 1.30 2012/10/07 11:54:46 asau Exp $

DISTNAME=		pymsnt-0.11.3
PKGREVISION=		3
PKGNAME=		${PYPKGPREFIX}-jabber-${DISTNAME:S/py//}
CATEGORIES=		chat python
MASTER_SITES=		http://delx.net.au/projects/pymsnt/tarballs/

PATCH_SITES=		http://www.darkskies.za.net/~norman/msn/
PATCHFILES=		hg-214.patch
PATCH_DIST_STRIP.hg-214.patch=	-p1

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://delx.net.au/projects/pymsnt
COMMENT=		Transport connecting Jabber to the MSN network
LICENSE=		gnu-gpl-v2

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-twisted>=8.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1.5:../../graphics/py-imaging

# Fifth paragraph - all build definitions that describe things used by
# the package.  These include: WRKSRC, GNU_CONFIGURE,
# HAS_CONFIGURE, USE_PKGLOCALEDIR, USE_INSTALL, TEXINFO_REQD, USE_JAVA,
# USE_PERL5, INFO_FILES, DIST_SUBDIR, etc.
# EXTRACT_ONLY=		# yes
NO_BUILD=		yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	pymsnt

PYTHON_PATCH_SCRIPTS+=	PyMSNt.py

TRANSPORTDIR=		${JABBER_TRANSDIR}/pymsnt

FILES_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PLIST_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS+=	${TRANSPORTDIR} bin

.include "../../wip/jabberd/transports.mk"

CONF_FILES=	${EGDIR}/pymsnt.xml ${PKG_SYSCONFDIR}/pymsnt.xml

do-install:
	cd ${WRKSRC} && \
	for i in `find src data \\( \\( -type f -name '*.orig' -o \
		    -type f -name '*.orig_dist' -o \
		    -type d -name .svn \\) -prune \\) -o -type f -print` ;\
	do \
	    ${ECHO} "Installing $$i -> " \
				"${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i";\
	    ${INSTALL_SCRIPT_DIR} \
			`${DIRNAME} ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i` ;\
	    ${INSTALL_SCRIPT} $$i ${DESTDIR}${PREFIX}/${TRANSPORTDIR}/$$i ;\
	done
	cd ${WRKSRC}; \
	${INSTALL_SCRIPT} PyMSNt.py ${DESTDIR}${PREFIX}/bin/PyMSNt
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR};\
	${INSTALL_DATA} ${WRKSRC}/config-example.xml \
						${DESTDIR}${EGDIR}/pymsnt.xml

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing Paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	config-example.xml PyMSNt.py src/main.py
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@TRANSPORTDIR@,${TRANSPORTDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_SPOOLDIR@,${JABBER_SPOOLDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_TRANSDIR@,${JABBER_TRANSDIR},g'
SUBST_SED.paths+=	-e 's,@JABBER_GROUP@,${JABBER_GROUP},g'
SUBST_SED.paths+=	-e 's,@JABBER_USER@,${JABBER_USER},g'
SUBST_SED.paths+=	-e 's,@JABBER_LOGDIR@,${JABBER_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@JABBER_PIDDIR@,${JABBER_PIDDIR},g'

.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
