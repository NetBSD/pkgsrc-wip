# $NetBSD$

GITHUB_PROJECT=	chapel
DISTNAME=	chapel-1.22.1
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=chapel-lang/}
GITHUB_RELEASE=	1.22.1

MAINTAINER=	jhigh@NetBSD.org
HOMEPAGE=	https://chapel-lang.org/
COMMENT=	The Chapel programming language
LICENSE=	apache-2.0

CONFIGURE_ARGS=		--prefix=/usr/pkg
USE_TOOLS=		bash pkg-config gmake perl
USE_LIBTOOL=		yes
REPLACE_BASH=		configure
REPLACE_BASH+=		modules/internal/fixInternalDocs.sh
REPLACE_SH=		third-party/qthread/qthread-src/configure

PYTHON_VERSIONS_ACCEPTED=	27
USE_LANGUAGES=	c c++ fortran

PKGCONFIG_OVERRIDE+=	third-party/hwloc/hwloc-src/hwloc.pc.in
PKGCONFIG_OVERRIDE+=	third-party/jemalloc/jemalloc-src/jemalloc.pc.in
PKGCONFIG_OVERRIDE+=	third-party/llvm/llvm-src/utils/benchmark/cmake/benchmark.pc.in

REPLACE_INTERPRETER+=		envpython
REPLACE.envpython.old=		'/usr/bin/env\ python'
REPLACE.envpython.new=		${PYTHONBIN}
REPLACE_FILES.envpython=	util/printchplenv
REPLACE_FILES.envpython+=	util/config/replace-paths.py
REPLACE_FILES.envpython+=	util/config/fixpath.py
REPLACE_FILES.envpython+=	util/chplenv/printchplenv.py
REPLACE_FILES.envpython+=	util/chplenv/overrides.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_unwind.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_timers.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_tasks.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_regexp.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_python_version.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_platform.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_mem.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_make.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_locale_model.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_llvm.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_launcher.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_hwloc.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_gmp.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_cpu.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_compiler.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_comm_substrate.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_comm_segment.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_comm_debug.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_comm.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_bin_subdir.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_aux_filesys.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_atomics.py
REPLACE_FILES.envpython+=	util/chplenv/chpl_arch.py
REPLACE_FILES.envpython+=	util/config/compileline
REPLACE_FILES.envpython+=	util/chplenv/third-party-pkgs

REPLACE_INTERPRETER+=		envsh
REPLACE.envsh.old=		'/usr/bin/env\ sh'
REPLACE.envsh.new=		${SH}
REPLACE_FILES.envsh=		util/printchplenv

REPLACE_INTERPRETER+=		envperl
REPLACE.envperl.old=		.*/bin/env\ perl
REPLACE.envperl.new=		${PERL5}
REPLACE_FILES.envperl=		modules/dists/fixDistDocs.perl

SUBST_CLASSES+=		penvperl
SUBST_STAGE.penvperl=	pre-install
SUBST_FILES.penvperl=	third-party/jemalloc/install/*/bin/jeprof
SUBST_SED.penvperl=	-e "s,/usr/bin/env perl,${PERL5},g"

do-configure:
	cd ${WRKSRC} && ./configure --prefix=/usr/pkg

.include "../../mk/bsd.pkg.mk"
.include "../../lang/gcc7/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/perl5/buildlink3.mk"
