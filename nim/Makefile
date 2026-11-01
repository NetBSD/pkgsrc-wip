# $NetBSD: Makefile,v 1.37 2024/05/16 09:59:20 pho Exp $

DISTNAME=	nim-2.4.0
CATEGORIES=	lang
MASTER_SITES=	http://nim-lang.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nim-lang.org/
COMMENT=	The Nim programming language
LICENSE=	mit

# Taken from:
# https://github.com/nim-lang/Nim/blob/14991af742d0833503741fd9a0918133d1bcf8a4/koch.nim
ATLAS_TAG=	aa6fb162006f3015aa84c4305e15cb4d230f5ad6
SAT_TAG=		9d52513b3c68bfb929dbd687d4fb2836cfee6936

GH_SFX=		.tar.gz

ATLAS_DISTNAME=		atlas-${ATLAS_TAG}
SAT_DISTNAME=			sat-${SAT_TAG}

ATLAS_DISTFILE=		${ATLAS_DISTNAME}${GH_SFX}
SAT_DISTFILE=			${SAT_DISTNAME}${GH_SFX}

DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		${ATLAS_DISTFILE}
DISTFILES+=		${SAT_DISTFILE}

SITES.${ATLAS_DISTFILE}=	-${MASTER_SITE_GITHUB:=nim-lang/atlas/archive/}${ATLAS_TAG}${GH_SFX}
SITES.${SAT_DISTFILE}=		-${MASTER_SITE_GITHUB:=nim-lang/sat/archive/}${SAT_TAG}${GH_SFX}

EXTRACT_DIR.${ATLAS_DISTFILE}=		${WRKSRC}
EXTRACT_DIR.${SAT_DISTFILE}=			${WRKSRC}

DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

USE_TOOLS+=	bash pax
REPLACE_BASH+=	bin/nim-gdb

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	lib/nim/tools/debug
INSTALLATION_DIRS+=	share/nimble/pkgs/nim-${PKGVERSION_NOREV}/dist/checksums
INSTALLATION_DIRS+=	share/nim
INSTALLATION_DIRS+=	include
INSTALLATION_DIRS+=	lib/nim/nimsuggest
INSTALLATION_DIRS+=	lib/nim/nimpretty

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	config/nim.cfg
SUBST_SED.paths=	-e 's,/usr/pkg,${PREFIX},g'

post-extract:
	# TODO: csources for cross-building?
	# ${MV} ${WRKSRC}/csources_v2-${C2VERSION_TAG} ${WRKSRC}/csources_v2
	${MKDIR} ${WRKSRC}/dist
	# ${MV} nimble-$_nimbleversion $build_wrksrc/dist/nimble
	#mv checksums-$_checksumsversion $build_wrksrc/dist/checksums
	#mkdir -p $build_wrksrc/dist/nimble/dist
	#cp -r $build_wrksrc/dist/checksums $build_wrksrc/dist/nimble/dist/checksums
	${MV} ${WRKSRC}/atlas-${ATLAS_TAG} ${WRKSRC}/dist/atlas

	${MKDIR} ${WRKSRC}/dist/atlas/dist
	${MV} ${WRKSRC}/sat-${SAT_TAG} ${WRKSRC}/dist/atlas/dist/sat

# Nim doesn't automatically passes LDFLAGS/CFLAGS variables to the compiler
# but rather uses its own --passL/--passC flags. The two lines below translate
# the flags so the nim compiler actually uses them.
NIM_FLAGS=	${LDFLAGS:S/^/--passL:/}
NIM_FLAGS+=	${CFLAGS:S/^/--passC:/}

do-build:
	# build nim csource
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} sh ./build.sh
	printf '#! %s\nexec %s _=%s/nim/bin/nim %s/nim/bin/nim "$$@"\n' \
		"${SH}" "${SETENV}" "${PREFIX}" "${PREFIX}" \
		> ${WRKSRC}/nim-wrapper.sh
	# build koch
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./bin/nim c \
		--skipUserCfg \
		--skipParentCfg \
		--parallelBuild:${_MAKE_JOBS_N} \
		koch

	# build nim
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch boot \
		--parallelBuild:${_MAKE_JOBS_N} \
		-d:release ${NIM_FLAGS}

	# build tools
	# TODO: build the 'external' tools, in separate packages
	# cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch --stable toolsNoExternal --parallelBuild:${_MAKE_JOBS_N} ${NIM_FLAGS}
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./koch \
		--stable tools \
		--parallelBuild:${_MAKE_JOBS_N} \
		${NIM_FLAGS}

	# build niminst
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./bin/nim compile \
		-d:release \
		--parallelBuild:${_MAKE_JOBS_N} \
		${NIM_FLAGS} \
		tools/niminst/niminst.nim

do-install:
	cd ${WRKSRC} && sh ./install.sh ${DESTDIR}${PREFIX}
	cd ${WRKSRC}/bin && ${PAX} -r -w . ${DESTDIR}${PREFIX}/nim/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/nim-wrapper.sh ${DESTDIR}${PREFIX}/bin/nim
	# ${RM} ${DESTDIR}${PREFIX}/nim/bin/nim-gdb.orig
	${INSTALL} ${WRKSRC}/tools/niminst/niminst ${DESTDIR}${PREFIX}/nim/bin/
.for x in nim-gdb nim_dbg nimgrep niminst nimpretty nimsuggest testament
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf ${DESTDIR}${PREFIX}/nim/bin/${x} ${x}
.endfor
	cd ${WRKSRC}/tools/debug/ && ${PAX} -r -w . ${DESTDIR}${PREFIX}/lib/nim/tools/debug/

	# This is imported from share/nimble/pkgs/nim-*/compiler/nimblecmd.nim.
	cd ${WRKSRC}/dist/checksums/ && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/nimble/pkgs/nim-${PKGVERSION_NOREV}/dist/checksums/

.for d in nimsuggest nimpretty
	cd ${WRKSRC}/${d} && ${PAX} -r -w . ${DESTDIR}${PREFIX}/lib/nim/${d}/
	${LN} -sf ${DESTDIR}${PREFIX}/lib/nim/${d} ${DESTDIR}${PREFIX}/share/nim/${d}
.endfor

do-test:
	cd ${WRKSRC} && ./bin/nim compile koch.nim
	cd ${WRKSRC} && LD_LIBRARY_PATH=${PREFIX}/lib ./koch test all \
		--parallelBuild:${_MAKE_JOBS_N}

.include "../../mk/bsd.pkg.mk"
