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
DEPENDS+=	${PYPKGPREFIX}-manticore-[0-9]*:../../devel/py-manticore

PYTHON_VERSIONS_ACCEPTED=	27

post-install:
	${MV} ${FAKEHOMEDIR}/.local/bin/deepstate ${DESTDIR}${PREFIX}/bin
	${MV} ${FAKEHOMEDIR}/.local/bin/deepstate-angr ${DESTDIR}${PREFIX}/bin
	${MV} ${FAKEHOMEDIR}/.local/bin/deepstate-manticore ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
