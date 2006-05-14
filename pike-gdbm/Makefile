# $NetBSD: Makefile,v 1.1 2006/05/14 21:21:40 cheusov Exp $

PKGNAME=	pike-gdbm-${PIKE_VERSION}
CATEGORIES=	wip
COMMENT=	dynamic programming language with a syntax similar to C++

MODULE_NAMES=	Gdbm
MODULE_DIRS=	modules/Gdbm
MODULE_SO=	Gdbm.so

.include "../../wip/pike-core/Makefile.common"
.include "../../wip/pike-core/Makefile.modules_common"

.include "../../databases/gdbm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
