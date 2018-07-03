# $NetBSD: Makefile,v 1.14 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	Proxy65-1.2.0
PKGNAME=	${PYPKGPREFIX}-jabber-${DISTNAME:S/P/p/}
CATEGORIES=	chat python
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/proxy65/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://proxy65.googlecode.com/
COMMENT=	XEP-0065 proxy transport for XMPP
LICENSE=	mit

#
# jabberd isn't really a dependency since the transport can run on a
# different server than the main jabber server (not that many sites will
# do that..)
#
# DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd2
DEPENDS+=	${PYPKGPREFIX}-twisted>=8.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-automat-[0-9]*:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 1.2.0

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

JABBER_USER?=		jabberd
JABBER_GROUP?=		jabberd
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}
PKG_USERS_VARS=		JABBER_USER
PKG_GROUPS_VARS+=	JABBER_GROUP

.include "../../wip/jabberd/transports.mk"

DOCDIR=			${DESTDIR}${PREFIX}/share/doc/proxy65
DOCFILES=		README

INSTALLATION_DIRS=	share/doc/proxy65

RCD_SCRIPTS=	proxy65

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
