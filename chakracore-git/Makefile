# $NetBSD: Makefile,v 1.3 2015/04/25 10:01:54 krytarowski Exp $

GIT_REPOSITORIES=	chakracore
GIT_REPO.chakracore=	https://github.com/Microsoft/ChakraCore.git

DISTNAME=	chakracore
PKGNAME=	chakracore-0.0.0
CATEGORIES=	lang

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/Microsoft/chakracore
COMMENT=	Core part of the Chakra Javascript engine that powers Microsoft Edge
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CXXFLAGS+=	-std=c++11

.include "../../wip/mk/git-package.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
