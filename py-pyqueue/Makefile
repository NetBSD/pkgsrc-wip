# $NetBSD: Makefile,v 1.1 2014/05/02 09:00:34 ahp-nils Exp $

DISTNAME=	0.4
PKGNAME=	${PYPKGPREFIX}-pyqueue-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://github.com/outini/pyqueue/archive/

MAINTAINER=	ahp-nils@users.sourceforge.net
HOMEPAGE=	https://github.com/outini/pyqueue/
COMMENT=	Postfix queue control python tool
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/pyqueue-0.4
USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	27

#.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
