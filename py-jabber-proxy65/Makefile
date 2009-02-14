# $NetBSD: Makefile,v 1.9 2009/02/14 05:31:25 schnoebe Exp $

DISTNAME=	Proxy65-1.2.0
PKGNAME=	${PYPKGPREFIX}-jabber-${DISTNAME:S/P/p/}
CATEGORIES=	chat python
MASTER_SITES=	http://proxy65.googlecode.com/files/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://code.google.com/p/proxy65/
COMMENT=	XEP-0065 proxy transport for XMPP

PKG_DESTDIR_SUPPORT=	user-destdir
#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted>=8.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

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

DOCDIR=                 ${DESTDIR}${PREFIX}/share/doc/proxy65
DOCFILES=               README

INSTALLATION_DIRS=	share/doc/proxy65

RCD_SCRIPTS=	proxy65

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
