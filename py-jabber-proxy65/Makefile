# $NetBSD: Makefile,v 1.3 2008/08/07 22:17:25 schnoebe Exp $

DISTNAME=	Proxy65-1.1.1
PKGNAME=	${PYPKGPREFIX}-jabber-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	http://proxy65.googlecode.com/files/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://code.google.com/p/proxy65/
COMMENT=	XEP-0065 proxy transport for XMPP

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-words>=8.1.0:../../wip/py-twisted-words
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

# it's a python package using the standard Python packager
PYDISTUTILSPKG=	yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

DOCDIR=                 ${PREFIX}/share/doc/proxy65
DOCFILES=               README


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
