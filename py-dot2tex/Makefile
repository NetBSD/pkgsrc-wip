# $NetBSD$

DISTNAME=	dot2tex-2.11.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	 print python
MASTER_SITES=	https://files.pythonhosted.org/packages/49/03/a0ce345bb4b816fffb9107dcbad2f9bd1dd2db314b9fdb782cd398c95c96/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/kjellmf/dot2tex
COMMENT=	Graphviz to LaTeX converter
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES+=	pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
