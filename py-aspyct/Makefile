# $NetBSD: Makefile,v 1.2 2009/06/21 21:10:20 jihbed Exp $
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

PYTHON_VERSIONS_ACCEPTED=  26 25 24
PYDISTUTILSPKG=	yes


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
