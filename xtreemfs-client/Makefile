# $NetBSD: Makefile,v 1.2 2012/07/02 13:38:10 moubctez Exp $

PKGNAME=	${DISTNAME:S/XtreemFS/xtreemfs-client/}
PKGREVISION=	1

USE_LANGUAGES+=		c c++

BUILD_TARGET=		client
INSTALL_TARGET=		install-client

.include "../../wip/xtreemfs-server/Makefile.common"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
