# $NetBSD: Makefile,v 1.2 2018/02/22 23:41:31 khorben Exp $

DISTNAME=	deepstate-0.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=trailofbits/}
GITHUB_PROJECT=	deepstate
GITHUB_TAG=	ca5fada9f4653b6c808fc079907c9a90fb5b057b

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/trailofbits/deepstate/
COMMENT=	Augments C/C++ Test-Driven Development with Symbolic Execution
LICENSE=	apache-2.0

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

PYTHON_VERSIONS_ACCEPTED=	27

CMAKE_ARG_PATH=	${WRKSRC}
CONFIGURE_DIRS=	${WRKSRC}/build
PYSETUPSUBDIR=	build

pre-configure:
	${MKDIR} ${WRKSRC}/build

post-install:
	${MV} ${FAKEHOMEDIR}/.local/bin/futurize ${DESTDIR}${PREFIX}/bin
	${MV} ${FAKEHOMEDIR}/.local/bin/pasteurize ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
