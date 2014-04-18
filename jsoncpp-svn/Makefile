# $NetBSD: Makefile,v 1.1 2014/04/18 22:27:54 thomasklausner Exp $

DISTNAME=	jsoncpp-0.6.0rc2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jsoncpp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsoncpp.sourceforge.net/
COMMENT=	JSON reader and writer in C++
LICENSE=	mit

SVN_REPOSITORIES=	json-cpp
SVN_ROOT.json-cpp=	http://svn.code.sf.net/p/jsoncpp/code/trunk/jsoncpp

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/json-cpp

# for tests
PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.6.0rc2nb20140217

.include "../../lang/python/application.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
