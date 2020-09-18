# $NetBSD$

MASTER_SITES=	${MASTER_SITE_GITHUB:=trailofbits/}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	${PYPKGPREFIX}-angr-[0-9]*:../../devel/py-angr
DEPENDS+=	${PYPKGPREFIX}-cachetools-[0-9]*:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-manticore-[0-9]*:../../devel/py-manticore
DEPENDS+=	${PYPKGPREFIX}-networkx-[0-9]*:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pefile-[0-9]*:../../sysutils/py-pefile
DEPENDS+=	${PYPKGPREFIX}-ana-[0-9]*:../../wip/py-ana
DEPENDS+=	${PYPKGPREFIX}-bintrees-[0-9]*:../../wip/py-bintrees
DEPENDS+=	${PYPKGPREFIX}-bitstring-[0-9]*:../../wip/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-cooldict-[0-9]*:../../wip/py-cooldict
DEPENDS+=	${PYPKGPREFIX}-dpkt-fix-[0-9]*:../../wip/py-dpkt-fix
DEPENDS+=	${PYPKGPREFIX}-idalink-[0-9]*:../../wip/py-idalink
DEPENDS+=	${PYPKGPREFIX}-mulpyplexer-[0-9]*:../../wip/py-mulpyplexer
DEPENDS+=	${PYPKGPREFIX}-progressbar-[0-9]*:../../wip/py-progressbar
DEPENDS+=	${PYPKGPREFIX}-pygit-[0-9]*:../../wip/py-pygit
DEPENDS+=	${PYPKGPREFIX}-rpyc-[0-9]*:../../wip/py-rpyc

PYTHON_VERSIONS_ACCEPTED=	37 36

CMAKE_ARG_PATH=	${WRKSRC}
CONFIGURE_DIRS=	${WRKSRC}/build
PYSETUPSUBDIR=	build

pre-configure:
	${MKDIR} ${WRKSRC}/build

post-install:
	${MV} ${FAKEHOMEDIR}/.local/bin/futurize ${DESTDIR}${PREFIX}/bin
	${MV} ${FAKEHOMEDIR}/.local/bin/pasteurize ${DESTDIR}${PREFIX}/bin

.include "Makefile.common"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
