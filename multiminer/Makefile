# $NetBSD: Makefile,v 1.2 2014/10/26 18:25:41 noud4 Exp $

DISTNAME=	multiminer-3.6.2
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=nwoolls/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	https://github.com/nwoolls/MultiMiner
COMMENT=	Bitcoin miner front-end
LICENSE=	mit

DEPENDS+=	bfgminer>=3.9.0:../../wip/bfgminer

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	multiminer	
SUBST_SED.path=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.path=	"Fixing path."

post-extract:
	cp ${FILESDIR}/multiminer.sh ${WRKSRC}/multiminer

do-build:
	cd ${WRKSRC} && MONO_IOMAP=case xbuild MultiMiner.sln

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/multiminer/Miners/BFGMiner
	cp -r ${WRKSRC}/MultiMiner.Win/bin/Debug/* ${DESTDIR}${PREFIX}/multiminer
	ln -sf ${PREFIX}/bin/bfgminer ${DESTDIR}${PREFIX}/multiminer/Miners/BFGMiner
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/multiminer ${DESTDIR}${PREFIX}/bin

.include "../../lang/mono2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
