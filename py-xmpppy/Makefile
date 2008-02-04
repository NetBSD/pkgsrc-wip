# $NetBSD: Makefile,v 1.5 2008/02/04 17:47:31 schnoebe Exp $

DISTNAME=		xmpppy-0.4.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		chat python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmpppy/}

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://xmpppy.sourceforge.net/
COMMENT=		XMPP (Jabber) library for Python

PYTHON_VERSIONS_INCOMPATIBLE=	15 20 
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
