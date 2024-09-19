# $NetBSD$

.include "../../wip/mlt/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	multimedia python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mltframework.org/
COMMENT=	Open source multimedia framework (Python bindings)
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	swig3-[0-9]*:../../devel/swig3

USE_LANGUAGES=	c c++

CXXFLAGS+=	-DHAVE_LOCALE_H

MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}

PY_PATCHPLIST=	yes

INSTALLATION_DIRS+=	${PYSITELIB}

do-build:
	cd ${WRKSRC}/src/swig/python && ${MAKE_ENV} ./build

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/swig/python/mlt.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/mlt.py
	${INSTALL_LIB} ${WRKSRC}/src/swig/python/_mlt.so \
		${DESTDIR}${PREFIX}/${PYSITELIB}/_mlt.so

.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/mlt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
