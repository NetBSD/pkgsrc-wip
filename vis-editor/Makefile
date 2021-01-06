# $NetBSD$

DISTNAME=		vis-0.7
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

LUA_VERSIONS_ACCEPTED=	52 53

USE_TOOLS+=		pkg-config

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sharedir=${PREFIX}/share
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		vis-lua.c man/vis.1 Makefile
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/share/${DISTBASE},/share/${PKGBASE},g'
SUBST_SED.fix-paths+=		-e 's,$${SHAREPREFIX}/${DISTBASE},$${SHAREPREFIX}/${PKGBASE},g'
SUBST_SED.fix-paths+=		-e 's,$${DOCPREFIX}/${DISTBASE},$${DOCPREFIX}/${PKGBASE},g'

SUBST_CLASSES+=			binary-names
SUBST_STAGE.binary-names=	pre-build
SUBST_MESSAGE.binary-names=	Fixing binary names.
SUBST_FILES.binary-names+=	man/*.1
SUBST_FILES.binary-names+=	lua/plugins/*.lua
SUBST_FILES.binary-names+=	main.c vis-menu.c vis-registers.c vis.h
SUBST_FILES.binary-names+=	vis-complete vis-open
SUBST_SED.binary-names=		-e 's,'${DISTBASE}'-\(open\),'${PKGBASE}'-\1,g'
SUBST_SED.binary-names+=	-e 's,'${DISTBASE}'-\(clipboard\),'${PKGBASE}'-\1,g'
SUBST_SED.binary-names+=	-e 's,'${DISTBASE}'-\(complete\),'${PKGBASE}'-\1,g'
SUBST_SED.binary-names+=	-e 's,'${DISTBASE}'-\(digraph\),'${PKGBASE}'-\1,g'
SUBST_SED.binary-names+=	-e 's,'${DISTBASE}'-\(menu\),'${PKGBASE}'-\1,g'

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE}-open ${DESTDIR}${PREFIX}/bin/${PKGBASE}-open
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE}-clipboard ${DESTDIR}${PREFIX}/bin/${PKGBASE}-clipboard
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE}-complete ${DESTDIR}${PREFIX}/bin/${PKGBASE}-complete
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE}-digraph ${DESTDIR}${PREFIX}/bin/${PKGBASE}-digraph
	${MV} ${DESTDIR}${PREFIX}/bin/${DISTBASE}-menu ${DESTDIR}${PREFIX}/bin/${PKGBASE}-menu
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${DISTBASE}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${DISTBASE}-open.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}-open.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${DISTBASE}-clipboard.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}-clipboard.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${DISTBASE}-complete.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}-complete.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${DISTBASE}-digraph.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}-digraph.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${DISTBASE}-menu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}-menu.1

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../wip/libtermkey/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
