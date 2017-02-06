# $NetBSD$

DISTNAME=		vis-0.2
PKGNAME=		${DISTNAME:S/vis/vis-editor/}
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=martanne/}

MAINTAINER=		erig@erig.me
HOMEPAGE=		https://github.com/martanne/vis/
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

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sharedir=${PREFIX}/share
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		vis-lua.c vis.1
SUBST_SED.fix-paths=		-e "s,/usr/local,${PREFIX},g"
SUBST_SED.fix-paths+=		-e "s,/share/vis,/share/${PKGBASE},g"

SUBST_CLASSES+=			vis-open
SUBST_STAGE.vis-open=		pre-build
SUBST_FILES.vis-open=		vis-cmds.c
SUBST_SED.vis-open=		-e 's,\("[^"]*\)'${DISTBASE}-open'\([^"]*"\),\1'${PKGBASE}-open'\2,g'

SUBST_CLASSES+=				vis-clipboard
SUBST_STAGE.vis-clipboard=		pre-build
SUBST_FILES.vis-clipboard=		register.c
SUBST_SED.vis-clipboard=		-e 's,\("[^"]*\)'${DISTBASE}-clipboard'\([^"]*"\),\1'${PKGBASE}-clipboard'\2,g'

SUBST_CLASSES+=		fix-pie
SUBST_STAGE.fix-pie=	pre-configure
SUBST_MESSAGE.fix-pie=	Fixing LDFLAGS -pie flag.
SUBST_FILES.fix-pie=	configure
SUBST_SED.fix-pie=	-e "s,-Wl[,]-pie,-pie,g"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE}-open ${DESTDIR}${PREFIX}/bin/${PKGBASE}-open
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE}-clipboard ${DESTDIR}${PREFIX}/bin/${PKGBASE}-clipboard
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${DISTBASE}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1
	${MV} ${DESTDIR}${PREFIX}/share/${DISTBASE} ${DESTDIR}${PREFIX}/share/${PKGBASE}

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../wip/libtermkey/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
