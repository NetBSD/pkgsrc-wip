# $NetBSD: Makefile,v 1.2 2006/11/29 19:05:45 cheusov Exp $

PKGNAME=	pike-Gz-${PIKE_VERSION}
CATEGORIES=	lang
COMMENT=	Gz module for Pike programming language
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mpl-1.1

MODULE_NAMES=	Gz
MODULE_DIRS=	modules/Gz
MODULE_SO=	___Gz.so

.include "../../wip/pike-core/Makefile.common"
.include "../../wip/pike-core/Makefile.modules_common"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
