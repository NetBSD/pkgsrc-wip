# $NetBSD: Makefile,v 1.1.1.1 2011/11/08 01:47:03 tnn2 Exp $
#

PKGNAME=		${DISTNAME:S/XtreemFS/xtreemfs-client/}

USE_LANGUAGES+=		c c++

BUILD_TARGET=		client
INSTALL_TARGET=		install-client

.include "../../wip/xtreemfs-server/Makefile.common"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
