# $NetBSD: Makefile,v 1.1 2013/05/24 04:17:19 othyro Exp $
#

DISTNAME=	pyrit-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net security
MASTER_SITES=	http://pyrit.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pyrit/
COMMENT=	WPA/WPA2-PSK and a world of affordable many-core platforms
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG=	YES
REPLACE_PYTHON=	setup.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
