# $NetBSD: Makefile,v 1.2 2018/02/22 23:41:31 khorben Exp $

DISTNAME=	deepstate-0.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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

DEPENDS+=	deepstate-[0-9]*:../../wip/deepstate

PYTHON_VERSIONS_ACCEPTED=	27

CMAKE_ARG_PATH=	${WRKSRC}
CONFIGURE_DIRS=	${WRKSRC}/build
PYSETUPSUBDIR=	build

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
