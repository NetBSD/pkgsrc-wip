# $NetBSD$

DISTNAME=		translate-toolkit-3.0.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=translate/}
GITHUB_PROJECT=	translate
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://toolkit.translatehouse.org/
COMMENT=	Essential Toolkit for Localization Engineers
LICENSE=	gnu-gpl-v1

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=1.9.0:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-diff-match-patch>=0:../../textproc/py-diff-match-patch/

#USE_LANGUAGES=	c
PYTHON_VERSIONS_INCOMPATIBLE= 27

USE_TOOLS+=	bash:run
REPLACE_BASH=	tools/*

# We do not want to setup a build env to translate
# Firefox and Firefox Mobile.
post-extract:
	${RM} ${WRKSRC}/tools/mozilla/*
	${RMDIR} ${WRKSRC}/tools/mozilla/

.include "options.mk"
#.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
