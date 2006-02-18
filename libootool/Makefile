# $NetBSD: Makefile,v 1.3 2006/02/18 23:09:54 tnn2 Exp $
#

DISTNAME=	libootool
CATEGORIES=	devel

MAINTAINER=	tnn+nbsd@nygren.pp.se
HOMEPAGE=	http://dcgui.berlios.de/
COMMENT=	Free to use c++ utility classes (used by wip/valknut)

BROKEN=		xxx: re-enable this package when wip/valknut tracks HEAD
BROKEN+=	and actually requires it.

.include "../../wip/valknut/Makefile.common"

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
