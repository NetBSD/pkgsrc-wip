# $NetBSD: Makefile,v 1.2 2014/05/02 12:08:06 ahp-nils Exp $

DISTNAME=		0.4
EGG_NAME=		pyqueue-${DISTNAME}
DIST_SUBDIR=	${EGG_NAME}
PKGNAME=		${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=		net
MASTER_SITES=	https://github.com/outini/pyqueue/archive/

MAINTAINER=	ahp-nils@users.sourceforge.net
HOMEPAGE=	https://github.com/outini/pyqueue/
COMMENT=	Postfix queue control python tool
LICENSE=	gnu-gpl-v2

WRKSRC=						${WRKDIR}/pyqueue-0.4
USE_LANGUAGES=				# none
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
