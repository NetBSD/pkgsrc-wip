# $NetBSD: Makefile,v 1.8 2009/02/14 05:31:25 schnoebe Exp $

DISTNAME=		xmpppy-0.4.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		chat python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmpppy/}

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://xmpppy.sourceforge.net/
COMMENT=		XMPP (Jabber) library for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
