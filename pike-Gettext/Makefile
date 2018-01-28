# $NetBSD: Makefile,v 1.1 2006/11/16 22:24:07 cheusov Exp $

PKGNAME=	pike-Gettext-${PIKE_VERSION}
CATEGORIES=	lang
COMMENT=	Gettext module for Pike programming language

MODULE_NAMES=	Gettext
MODULE_DIRS=	modules/Gettext
MODULE_SO=	Gettext.so

.include "../../wip/pike-core/Makefile.common"
.include "../../wip/pike-core/Makefile.modules_common"

.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
