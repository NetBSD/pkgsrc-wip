# $NetBSD: Makefile,v 1.1.1.1 2009/04/12 08:32:34 jihbed Exp $
#

DISTNAME=	Aspyct-3.0_beta_4
PKGNAME=	${PYPKGPREFIX}-aspyct-3.0-beta4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aspyct/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.aspyct.org/
COMMENT=	Python library including an aspect-oriented programming (AOP) engine

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

 PYTHON_VERSIONS_ACCEPTED=  25 24
PYDISTUTILSPKG=	yes


.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
