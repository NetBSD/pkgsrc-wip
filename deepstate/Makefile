# $NetBSD$

MASTER_SITES=	${MASTER_SITE_GITHUB:=trailofbits/}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	${PYPKGPREFIX}-angr-[0-9]*:../../wip/py-angr
DEPENDS+=	${PYPKGPREFIX}-cachetools-[0-9]*:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-gitpython-[0-9]*:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-manticore-[0-9]*:../../wip/py-manticore
DEPENDS+=	${PYPKGPREFIX}-networkx-[0-9]*:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pefile-[0-9]*:../../sysutils/py-pefile
DEPENDS+=	${PYPKGPREFIX}-ana-[0-9]*:../../wip/py-ana
DEPENDS+=	${PYPKGPREFIX}-bintrees-[0-9]*:../../wip/py-bintrees
DEPENDS+=	${PYPKGPREFIX}-bitstring-[0-9]*:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-cooldict-[0-9]*:../../wip/py-cooldict
DEPENDS+=	${PYPKGPREFIX}-dpkt-[0-9]*:../../wip/py-dpkt
#DEPENDS+=	${PYPKGPREFIX}-idalink-[0-9]*:../../wip/py-idalink
DEPENDS+=	${PYPKGPREFIX}-mulpyplexer-[0-9]*:../../wip/py-mulpyplexer
#DEPENDS+=	${PYPKGPREFIX}-progressbar-[0-9]*:../../wip/py-progressbar
DEPENDS+=	${PYPKGPREFIX}-rpyc-[0-9]*:../../wip/py-rpyc
DEPENDS+=	${PYPKGPREFIX}-z3solver-[0-9]*:../../math/py-z3solver

PYTHON_VERSIONS_ACCEPTED=	37 36

CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=       -DPYTHON=${PREFIX}/bin/python${PYVERSSUFFIX}
CONFIGURE_DIRS=	${WRKSRC}/build
PYSETUPSUBDIR=	build

pre-configure:
	${MKDIR} ${WRKSRC}/build

post-install:
.for binaryfile in deepstate-afl deepstate-angora deepstate-eclipser \
	deepstate-ensembler deepstate-honggfuzz deepstate-libfuzzer \
	deepstate-manticore deepstate-reduce futurize pasteurize
	${MV} ${FAKEHOMEDIR}/.local/bin/${binaryfile} ${DESTDIR}${PREFIX}/bin
.endfor

.include "Makefile.common"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
