# $NetBSD$

#PKGNAME=	translate-toolkit-2.0.0
DISTNAME=	translate-toolkit-2.0.0b7
GITHUB_PROJECT=	translate
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=translate/}
#MASTER_SITES=	https://github.com/translate/translate/releases/download/2.0.0b7/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://toolkit.translatehouse.org/
COMMENT=	Essential Toolkit for Localization Engineers
LICENSE=	gnu-gpl-v1

USE_LANGUAGES=	c

REPLACE_BASH=	${WRKSRC}/tools/junitmsgfmt \
		${WRKSRC}/tools/pocommentclean \
		${WRKSRC}/tools/pocompendium \
		${WRKSRC}/tools/pomigrate2 \
		${WRKSRC}/tools/popuretext \
		${WRKSRC}/tools/poreencode \
		${WRKSRC}/tools/posplit \

post-extract:
	${RM} ${WRKSRC}/tools/mozilla/build_firefox.sh
	${RM} ${WRKSRC}/tools/mozilla/buildxpi.py
	${RM} ${WRKSRC}/tools/mozilla/get_moz_enUS.py
	${RMDIR} ${WRKSRC}/tools/mozilla/

.include "options.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
