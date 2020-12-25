# $NetBSD$

DISTNAME=	junit-xml-2-1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-2/2/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=j/junit-xml-2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kyrus/python-junit-xml
COMMENT=	Python module for creating JUnit XML test result documents
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

EGG_NAME=	junit_xml-${PKGVERSION_NOREV}

USE_LANGUAGES=	# none

SUBST_CLASSES+=			rename-package
SUBST_STAGE.rename-package=	pre-configure
SUBST_MESSAGE.rename-package=	Rename the package to junit_xml
SUBST_FILES.rename-package+=	junit_xml.egg-info/SOURCES.txt
SUBST_FILES.rename-package+=	junit_xml.egg-info/top_level.txt
SUBST_FILES.rename-package+=	setup.py
SUBST_SED.rename-package+=	-e 's,junit_xml_2,junit_xml,g'
SUBST_SED.rename-package+=	-e 's,junit-xml-2,junit-xml,g'

post-extract:
	${MV} ${WRKSRC}/junit_xml_2.egg-info ${WRKSRC}/junit_xml.egg-info
	${MV} ${WRKSRC}/junit_xml_2 ${WRKSRC}/junit_xml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
