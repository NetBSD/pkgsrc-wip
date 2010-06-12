# $NetBSD: Makefile,v 1.1.1.1 2010/06/12 23:30:46 jihbed Exp $
#
VERS=	0.8.5
DISTNAME=	PyAIML-${VERS}
PKGNAME=	${PYPKGPREFIX}-pyaiml-${VERS}
CATEGORIES=	devel
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pyaiml/PyAIML%20%28unstable%29/0.8.5/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyaiml.sourceforge.net/
COMMENT=	PyAIML is an interpreter for AIML
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
