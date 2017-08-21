# $NetBSD: Makefile,v 1.1 2015/08/19 19:42:29 yhardy Exp $

DISTNAME=	ia-19.1
PKGNAME=	infraarcana-19.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=martin-tornqvist/}
GITHUB_PROJECT=	ia
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGBASE}
DISTFILES=	${DEFAULT_DISTFILES} rl_utils-${RLUTILSVER}.zip

RLUTILSVER=	86c9cc3dfca4782f78050c282e435168d2b7ba29

SITES.rl_utils-${RLUTILSVER}.zip=	\
		-${MASTER_SITES:=rl_utils/archive/${RLUTILSVER}.zip}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/infraarcana/
COMMENT=	Infra Arcana is a Lovecraftian roguelike set in the early 20th century
LICENSE=	cc-by-nc-sa-v3.0-license

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_GAMESGROUP=	yes

INSTALLATION_DIRS+=	bin

post-extract:
	${UNZIP_CMD} -d ${WRKSRC}/rl_utils ${DISTDIR}/${DIST_SUBDIR}/rl_utils-${RLUTILSVER}.zip
	cd ${WRKSRC}/rl_utils && ${MV} rl_utils-${RLUTILSVER}/* .

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/infraarcana.sh > ${WRKSRC}/infraarcana.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/infraarcana.sh ${DESTDIR}${PREFIX}/bin/infraarcana

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
