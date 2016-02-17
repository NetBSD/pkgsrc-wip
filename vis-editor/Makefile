# $NetBSD$

DISTNAME=		vis-0.1
PKGNAME=		${DISTNAME:S/vis/vis-editor/}
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_GITHUB:=martanne/}

MAINTAINER=		erig@erig.me
HOMEPAGE=		${MASTER_SITE_GITHUB:=martanne/vis/}
COMMENT=		Vim like text editor
LICENSE=		isc

GITHUB_PROJECT=		${DISTBASE}
GITHUB_TAG=		v${PKGVERSION_NOREV}

DISTBASE=		${DISTNAME:C/(.*)-${PKGVERSION}/\1/}

WRKSRC=			${WRKDIR}/${DISTNAME}

LUA_VERSIONS_ACCEPTED=	52

USE_TOOLS+=		gmake
USE_TOOLS+=		gsed
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
SUBST_CLASSES+=			zap-ldl
SUBST_MESSAGE.zap-ldl=		Remove -ldl from Makefiles.
SUBST_STAGE.zap-ldl=		pre-build
SUBST_FILES.zap-ldl=		Makefile config.mk
SUBST_SED.zap-ldl=		-e 's/-ldl//g'
.endif

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		config.mk vis-lua.c vis.1
SUBST_SED.fix-paths=		-e "s,/usr/local,${PREFIX},g"
SUBST_SED.fix-paths+=		-e "s,/share/man,/${PKGMANDIR},g"
SUBST_SED.fix-paths+=		-e "s,/share/vis,/share/${PKGBASE},g"

SUBST_CLASSES+=			vis-open
SUBST_STAGE.vis-open=		pre-build
SUBST_FILES.vis-open=		vis-cmds.c
SUBST_SED.vis-open=		-e 's,\("[^"]*\)'${DISTBASE}-open'\([^"]*"\),\1'${PKGBASE}-open'\2,g'

BUILD_TARGET=	vis

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE}-open ${DESTDIR}${PREFIX}/bin/${PKGBASE}-open
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${DISTBASE}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../wip/libtermkey/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
