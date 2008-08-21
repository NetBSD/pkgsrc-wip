# $NetBSD: Makefile,v 1.1.1.1 2008/08/21 20:54:16 schnoebe Exp $

DISTNAME=	palaver-0.5
PKGNAME=	${PYPKGPREFIX}-jabber-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	http://onlinegamegroup.com/releases/palaver/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.onlinegamegroup.com/projects/palaver/
COMMENT=	XEP-0045 + XEP-0128 Multi-User Conferencing package

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-words>=8.1.0:../../wip/py-twisted-words
# DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

# it's a python package using the standard Python packager
PYDISTUTILSPKG=	yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"


JABBER_USER?=		jabberd
JABBER_GROUP?=		jabberd
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PKG_USERS_VARS+=	JABBER_USER
PKG_GROUPS_VARS+=	JABBER_GROUP

.include "../../wip/jabberd/transports.mk"

# DOCDIR=                 ${PREFIX}/share/doc/proxy65
# DOCFILES=               README

# INSTALLATION_DIRS=	share/doc/proxy65

# RCD_SCRIPTS=	palaver

post-install:
# .for f in ${DOCFILES}
# 	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
# .endfor

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
