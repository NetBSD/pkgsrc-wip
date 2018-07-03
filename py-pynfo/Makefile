# $NetBSD: Makefile,v 1.10 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	pynfo-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pynfo/}
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pynfo.sourceforge.net/
COMMENT=	Nice, configureable info bot in Python

DEPENDS+=	${PYPKGPREFIX}-twisted>=1.1.1rc1:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.6.3

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
