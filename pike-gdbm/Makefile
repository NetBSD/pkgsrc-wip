# $NetBSD: Makefile,v 1.2 2006/05/14 21:27:00 cheusov Exp $

PKGNAME=	pike-gdbm-${PIKE_VERSION}
CATEGORIES=	lang
COMMENT=	GDBM module for Pike programming language
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mpl-1.1

MODULE_NAMES=	Gdbm
MODULE_DIRS=	modules/Gdbm
MODULE_SO=	Gdbm.so

.include "../../wip/pike-core/Makefile.common"
.include "../../wip/pike-core/Makefile.modules_common"

.include "../../databases/gdbm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
