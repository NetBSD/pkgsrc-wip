# $NetBSD: Makefile,v 1.4 2012/12/15 13:35:23 cheusov Exp $

# pike-* packages are not ready yet
PKGNAME=	pike-core-${PIKE_VERSION}
CATEGORIES=	lang
COMMENT=	Dynamic programming language with a syntax similar to C++
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mpl-1.1

MODULE_NAMES=	_ADT _math _Charset files system Nettle Gmp Math Parser \
		Regexp sprintf Unicode Locale

.for m in ${MODULE_NAMES}
MODULE_DIRS+=		modules/${m:Q}
.endfor

REPLACE_INTERPRETER+=	pike
REPLACE.pike.old=	/usr/bin/env pike
REPLACE.pike.new=	${PREFIX}/bin/pike78
REPLACE_FILES.pike=	src/modules/Gmp/prime_table.pike \
	src/post_modules/GTK/new_build_pgtk.pike \
	src/post_modules/GTK2/build_pgtk.pike \
	src/post_modules/Unicode/test.pike \
	lib/modules/Tools.pmod/Standalone.pmod/cflags.pike \
	lib/modules/Tools.pmod/Standalone.pmod/cgrep.pike \
	lib/modules/Tools.pmod/Standalone.pmod/dump.pike \
	lib/modules/Tools.pmod/Standalone.pmod/precompile.pike \
	lib/modules/Tools.pmod/Standalone.pmod/rsif.pike \
	lib/modules/Tools.pmod/Standalone.pmod/rsqld.pike \
	lib/modules/Tools.pmod/Standalone.pmod/test_pike.pike \
	bin/fake_dynamic_load.pike \
	bin/export.pike \
	bin/make_solaris_pkg.pike \
	bin/install.pike \
	bin/make_ci.pike \
	bin/make_interpret_functions.pike \
	bin/mkpeep.pike \
	bin/parse_install_log \
	bin/precompile.pike \
	bin/precompile_installed.pike \
	bin/tarfilter.pike \
	bin/test_pike.pike \
	bin/unbug \
	refdoc/chapters/preprocessor.xml \
	tools/changes2xml.pike

.include "../../wip/pike-core/Makefile.common"

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
