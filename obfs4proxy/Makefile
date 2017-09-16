# $NetBSD$

DISTNAME=	obfs4proxy-0.0.7
CATEGORIES=	security net
MASTER_SITES=	https://people.torproject.org/~yawning/releases/obfs4proxy/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	https://people.torproject.org/~yawning/releases/obfs4proxy/
COMMENT=	Look-like nothing obfuscation protocol
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	git.torproject.org/pluggable-transports/obfs4.git

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../wip/go-ed25519/buildlink3.mk"
.include "../../wip/go-siphash/buildlink3.mk"
.include "../../wip/go-goptlib/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
