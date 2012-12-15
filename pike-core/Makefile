# $NetBSD: Makefile,v 1.3 2012/12/15 00:13:02 cheusov Exp $

# pike-* packages are not ready yet
PKGNAME=	pike-core-${PIKE_VERSION}
CATEGORIES=	lang
COMMENT=	Dynamic programming language with a syntax similar to C++

MODULE_NAMES=	_ADT _math _Charset files system Nettle Gmp Math Parser \
		Regexp sprintf Unicode Locale

.for m in ${MODULE_NAMES}
MODULE_DIRS+=		modules/${m:Q}
.endfor

REPLACE_INTERPRETER+=	pike
REPLACE.pike.old=	/usr/bin/env pike
REPLACE.pike.new=	${PREFIX}/bin/pike
REPLACE_FILES.pike=	lib/modules/Tools.pmod/Standalone.pmod/rsqld.pike \
			lib/modules/Tools.pmod/Standalone.pmod/dump.pike \
			bin/precompile.pike

.include "../../wip/pike-core/Makefile.common"

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
