# $NetBSD: Makefile,v 1.1 2006/11/16 22:55:03 cheusov Exp $

PKGNAME=	pike-Regexp_PCRE-${PIKE_VERSION}
CATEGORIES=	lang
COMMENT=	Regexp_PCRE module for Pike programming language

MODULE_NAMES=	_Regexp_PCRE
MODULE_DIRS=	modules/_Regexp_PCRE
MODULE_SO=	____Regexp_PCRE.so

.include "../../wip/pike-core/Makefile.common"
.include "../../wip/pike-core/Makefile.modules_common"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
