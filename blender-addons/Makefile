# $NetBSD$

PKGVERSION=		3.5.0
BLENDERRELEASE=		${PKGVERSION:C/\.[0-9]*$//}
DISTNAME=		blender-addons-${PKGVERSION}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=blender/}
GITHUB_PROJECT=		blender-addons
GITHUB_TAG=		v${PKGVERSION}
GITHUB_SUBMODULES=	blender blender-addons-contrib ${GITHUB_TAG} ../blender-addons-contrib

MAINTAINER=		stix@stix.id.au
HOMEPAGE=		https://github.com/blender/blender-addons
COMMENT=		Standard set of blender addons
LICENSE=		gnu-gpl-v2

USE_TOOLS=		pax rm
NO_CONFIGURE=		YES
NO_BUILD=		YES
USE_LANGUAGES=		# none

PLIST_SUBST+=		BLENDERRELEASE=${BLENDERRELEASE:Q}

post-extract:
	cd ${WRKSRC} && ${RM} -r .gitea .github .gitignore
	cd ${WRKDIR}/blender-addons-contrib && ${RM} -r .gitea .github .gitignore

do-install:
	cd ${WRKSRC} && ${PAX} -rwv . ${DESTDIR}${PREFIX}/share/blender/${BLENDERRELEASE}/scripts/addons/
	cd ${WRKDIR}/blender-addons-contrib && ${PAX} -rwv . ${DESTDIR}${PREFIX}/share/blender/${BLENDERRELEASE}/scripts/addons/

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.pkg.mk"
