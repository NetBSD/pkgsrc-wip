# $NetBSD: Makefile,v 1.4 2008/08/13 04:56:31 schnoebe Exp $

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

INSTALLATION_DIRS=	share/doc/proxy65

RCD_SCRIPTS=	proxy65

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
