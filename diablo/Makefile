# $NetBSD: Makefile,v 1.4 2012/09/28 21:24:35 asau Exp $
#

DISTNAME=	diablo-5.1-REL
PKGNAME=	${DISTNAME:S/-REL//}
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.openusenet.org/diablo/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.openusenet.org/diablo/
COMMENT=	Newsfeeding and newsreading server software


BUILD_DEFS+=	IPV6_READY

WRKSRC=		${WRKDIR}/${DISTNAME}
NEWS_DIR=	${PREFIX}/news

#USE_TOOLS+=	xmake

BUILD_DEPENDS+=	xmake>=1.06:../../devel/xmake

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/XMakefile.inc
SUBST_STAGE.paths=	post-patch
SUBST_SED.paths=	-e 's,@@IDIR@@,${PREFIX}/news,'
SUBST_SED.paths+=	-e 's,@@MDIR@@,${PREFIX}/man,'
SUBST_SED.paths+=	-e 's,@@DIST@@,${PREFIX}/news,'

NEWS_USER?=		news
NEWS_GROUP?=		news
PKG_GROUPS=		${NEWS_GROUP}
PKG_USERS=		${NEWS_USER}:${NEWS_GROUP}
PKG_GECOS.${NEWS_USER}=	Diablo\ Internet\ News
PKG_HOME.${NEWS_USER}=	${NEWS_DIR}
PKG_SHELL.${NEWS_USER}=	${SH}


do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/xmake clean && ${PREFIX}/bin/xmake

pre-install:
	${MKDIR} ${NEWS_DIR}
	${CHOWN} -R ${NEWS_USER}:${NEWS_GROUP} ${NEWS_DIR}

do-install:
	cd ${WRKSRC} && ${PREFIX}/bin/xmake install

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
