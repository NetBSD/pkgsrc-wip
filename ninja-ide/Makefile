# $NetBSD: Makefile,v 1.1 2013/09/09 19:42:40 jihbed Exp $

DISTNAME=	v2.3
PKGNAME=	ninja-ide-2.3
EGG_NAME=	NINJA_IDE-2.3
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/ninja-ide/ninja-ide/archive/
EXTRACT_SUFX=	.zip
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ninja-ide.org/
COMMENT=	NINJA-IDE is a cross-platform integrated development environment
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/ninja-ide-2.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
