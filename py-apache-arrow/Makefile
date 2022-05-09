# $NetBSD$
ARROW_VERSION=	7.0.0
DISTNAME=	apache-arrow-${ARROW_VERSION}
PKGNAME=	${PYPKGPREFIX}-pyarrow-${ARROW_VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://dlcdn.apache.org/arrow/arrow-${ARROW_VERSION}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://arrow.apache.org/
COMMENT=	Python Bindings for Apache-Arrow
LICENSE=	apache-2.0

.include "../../mk/bsd.prefs.mk"
.include "../../wip/apache-arrow/options.mk"

PYSETUPSUBDIR=	python

USE_LANGUAGES=	c c++
BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
USE_TOOLS=	cmake gmake

MAKE_ENV+=	PYARROW_WITH_DATASET=1

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"
.include "../../wip/apache-arrow/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
