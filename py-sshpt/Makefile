# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:30 asau Exp $
#

DISTNAME=	sshpt-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://sshpt.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/sshpt/
COMMENT=	SSH Power Tool
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-m2crypto>=0.13:../../security/py-m2crypto
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko

WRKSRC=		${WRKDIR}/sshpt
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
