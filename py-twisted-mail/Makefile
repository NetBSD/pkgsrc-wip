# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 05:08:50 sifu Exp $

DISTNAME=		TwistedMail-${TWISTED_VERSION}
PKGNAME=		${PYPKGPREFIX}-twisted-mail-${TWISTED_VERSION}
CATEGORIES=             net python mail
MASTER_SITES=		http://tmrc.mit.edu/mirror/twisted/Mail/0.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.twistedmatrix.com/projects/mail/
COMMENT=		Mailserver and framework for Twisted

DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-twisted-names>=0.1.0:../../wip/py-twisted-names

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
TWISTED_VERSION=	0.1.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
