# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:21 thomasklausner Exp $

DISTNAME=	v2.3
PKGNAME=	ninja-ide-2.3
EGG_NAME=	NINJA_IDE-2.3
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/ninja-ide/ninja-ide/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ninja-ide.org/
COMMENT=	NINJA-IDE is a cross-platform integrated development environment
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/ninja-ide-2.3
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
