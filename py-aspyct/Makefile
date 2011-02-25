# $NetBSD: Makefile,v 1.3 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	Aspyct-3.0_beta_4
PKGNAME=	${PYPKGPREFIX}-aspyct-3.0-beta4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aspyct/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.aspyct.org/
COMMENT=	Python library including an aspect-oriented programming (AOP) engine
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=  27 26 25 24
PYDISTUTILSPKG=	yes


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
