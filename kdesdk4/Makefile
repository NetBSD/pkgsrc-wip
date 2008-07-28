# $NetBSD: Makefile,v 1.7 2008/07/28 09:41:48 mwdavies Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS+=	cervisia-[0-9]*
CONFLICTS+=	umbrello-[0-9]*

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DBUILD_kmtrace:BOOL=OFF

# disable for the moment till sort out -ldl
CMAKE_ARGS+=	-DBUILD_kstartperf:BOOL=OFF

REPLACE_PERL+= \
	scripts/cxxmetric \
	scripts/fixkdeincludes \
	scripts/fixuifiles \
	scripts/kdesvn-build \
	scripts/png2mng.pl \
	scripts/svnintegrate \
	kcachegrind/converters/dprof2calltree \
	kcachegrind/converters/memprof2calltree \
	kcachegrind/converters/op2calltree \
	cervisia/cervisia-change_repos_list.pl \
	cervisia/cervisia-normalize_cvsroot.pl \
	cervisia/change_colors.pl

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

USE_TOOLS+=	gmake

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../wip/kde4/kde4.mk"

.include "../../devel/libiberty/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
