# $NetBSD$

PKGNAME=	translate-toolkit-2.0.0
DISTNAME=	translate-toolkit-2.0.0rc1
GITHUB_PROJECT=	translate
CATEGORIES=	misc
#MASTER_SITES=	${MASTER_SITE_GITHUB:=translate/}
MASTER_SITES=	https://github.com/translate/translate/releases/download/2.0.0rc1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://toolkit.translatehouse.org/
COMMENT=	Essential Toolkit for Localization Engineers
LICENSE=	gnu-gpl-v1

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=	c

REPLACE_BASH=	tools/*
USE_TOOLS+=	bash:run
#REPLACE_INTERPRETER+=   bash
#REPLACE.bash.old=       /bin/bash
#REPLACE.bash.new=       /bin/sh
#REPLACE_FILES.bash=     tools/*

#SUBST_CLASSES+= testeq
#SUBST_STAGE.testeq=     post-extract
#SUBST_MESSAGE.testeq=   Replace non-portable "==" operator for test(1)
#SUBST_FILES.testeq+=    tools/*
#SUBST_SED.testeq=       -e 's/==/=/g'


#REPLACE_BASH=	${WRKSRC}/tools/junitmsgfmt \
#		${WRKSRC}/tools/pocommentclean \
#		${WRKSRC}/tools/pocompendium \
#		${WRKSRC}/tools/pomigrate2 \
#		${WRKSRC}/tools/popuretext \
#		${WRKSRC}/tools/poreencode \
#		${WRKSRC}/tools/posplit \

#AUTO_MKDIRS=yes

post-extract:
	${RM} ${WRKSRC}/tools/mozilla/build_firefox.sh
	${RM} ${WRKSRC}/tools/mozilla/buildxpi.py
	${RM} ${WRKSRC}/tools/mozilla/get_moz_enUS.py
	${RMDIR} ${WRKSRC}/tools/mozilla/

.include "options.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
