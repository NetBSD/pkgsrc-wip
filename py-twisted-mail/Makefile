# $NetBSD: Makefile,v 1.3 2007/02/04 19:26:55 milosn Exp $
.include "../../wip/py-twisted-core/version.mk"

MAIL_VERSION=	0.4.0
DISTNAME=	Twisted-${TWISTED_VERSION}
PKGNAME=	${PYPKGPREFIX}-twisted-mail-${MAIL_VERSION}
CATEGORIES=	net python mail
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Twisted/2.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.twistedmatrix.com/
COMMENT=	A Twisted e-mail server

WRKSRC=		${WRKDIR}/Twisted-${TWISTED_VERSION}/TwistedMail-${MAIL_VERSION}

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.5.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-names>=0.4.0:../../wip/py-twisted-names

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
