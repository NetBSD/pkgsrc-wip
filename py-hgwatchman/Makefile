# $NetBSD: Makefile,v 1.1 2015/02/13 12:00:53 nros Exp $

hgwver=		0.4.3
DISTNAME=	${hgwver}
PKGNAME=	${PYPKGPREFIX}-hgwatchman-${hgwver}
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/facebook/hgwatchman/get/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/facebook/hgwatchman/
COMMENT=	Mercuial status speedup
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/facebook-hgwatchman-ff079639962b

DEPENDS+=	watchman-[0-9]*:../../sysutils/watchman
DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

PYTHON_VERSIONS_INCOMPATIBLE=   33 34 35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
