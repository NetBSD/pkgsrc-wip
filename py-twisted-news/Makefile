# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 05:05:09 sifu Exp $

DISTNAME=		TwistedNews-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-news-${TWISTED_VERSION}
CATEGORIES=             net python
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/News/0.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/projects/news/
COMMENT=		Newsserver and framework for Twisted

DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-twisted-mail>=0.1.0:../../wip/py-twisted-mail

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	0.1.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
