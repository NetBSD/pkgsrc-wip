# $NetBSD: Makefile,v 1.4 2008/07/12 00:26:56 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

DISTNAME=	TwistedMail-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-mail-${TWISTED_VERSION}
CATEGORIES=	net python mail
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Mail/8.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	A Twisted e-mail server

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=8.1.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-names>=8.1.0:../../wip/py-twisted-names

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
