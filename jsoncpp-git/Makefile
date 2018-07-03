# $NetBSD: Makefile,v 1.2 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	jsoncpp-0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jsoncpp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-source-parsers/jsoncpp
COMMENT=	JSON reader and writer in C++
LICENSE=	public-domain OR mit

GIT_REPOSITORIES=	json-cpp
GIT_REPO.json-cpp=	git@github.com:open-source-parsers/jsoncpp.git

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/json-cpp

# for tests
PYTHON_FOR_BUILD_ONLY=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.6.0rc2nb20140217

.include "../../lang/python/application.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
