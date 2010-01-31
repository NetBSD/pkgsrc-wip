# $NetBSD: Makefile,v 1.5 2010/01/31 23:10:23 schnoebe Exp $
#

PKGNAME=	poco-${POCO_VERSION}
CATEGORIES=	devel

COMMENT=	POCO C++ libraries

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.include "../../wip/poco/Makefile.common"

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
