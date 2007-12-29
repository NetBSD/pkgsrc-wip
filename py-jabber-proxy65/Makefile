# $NetBSD: Makefile,v 1.1.1.1 2007/12/29 01:00:26 schnoebe Exp $

DISTNAME=	proxy65-read-only
PKGNAME=	${PYPKGPREFIX}-jabber-${DISTNAME:S/-read-only//}-20071228
CATEGORIES=	chat python
MASTER_SITES=	http://code.google.com/p/proxy65/downloads

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://code.google.com/p/proxy65/
COMMENT=	XEP-0065 proxy transport for XMPP

#
# Set up to grab 'distributions' from the google SVN repository.
#
SVN_REPOSITORIES=	proxy65
SVN_ROOT.proxy65=	http://proxy65.googlecode.com/svn/trunk/
SVN_MODULE.proxy65=	proxy65-read-only
SVN_TAG.proxy65=	{2007-12-28}

.include "../../wip/mk/svn-package.mk"

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.5.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-words>=0.5.0:../../wip/py-twisted-words

# it's a python package using the standard Python packager
PYDISTUTILSPKG=	yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

# RCD_SCRIPTS=	proxy65

# TRANSPORTDIR=		${JABBER_TRANSDIR}/pyaimt
#
# FILES_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
# FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
# PLIST_SUBST+=		TRANSPORTDIR=${TRANSPORTDIR:Q}
# MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
# MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}

# .include "../../wip/jabberd/transports.mk"

# CONF_FILES=	${EGDIR}/pyaimt.xml ${PKG_SYSCONFDIR}/pyaimt.xml

# pre-build:
# 	$(RM) $(WRKSRC)/proxy65/plugins.tml

# SUBST_CLASSES+=		paths
# SUBST_MESSAGE.paths=	Localizing Paths
# SUBST_STAGE.paths=	pre-configure
# SUBST_FILES.paths=	config_example.xml
# SUBST_FILES.paths+=	src/langs/__init__.py
# SUBST_FILES.paths+=	PyAIMt.py
# SUBST_FILES.paths+=	src/main.py
# SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
# SUBST_SED.paths+=	-e 's,@TRANSPORTDIR@,${TRANSPORTDIR},g'
# SUBST_SED.paths+=	-e 's,@JABBER_SPOOLDIR@,${JABBER_SPOOLDIR},g'
# SUBST_SED.paths+=	-e 's,@JABBER_TRANSDIR@,${JABBER_TRANSDIR},g'
# SUBST_SED.paths+=	-e 's,@JABBER_GROUP@,${JABBER_GROUP},g'
# SUBST_SED.paths+=	-e 's,@JABBER_USER@,${JABBER_USER},g'
# SUBST_SED.paths+=	-e 's,@JABBER_LOGDIR@,${JABBER_LOGDIR},g'
# SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
# SUBST_SED.paths+=	-e 's,@JABBER_PIDDIR@,${JABBER_PIDDIR},g'

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
