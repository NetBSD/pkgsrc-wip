# $NetBSD$

DISTNAME=		gnunet-go-0.0.20191112
CATEGORIES=		net
MASTER_SITES=		https://git.gnunet.org/gnunet-go.git

GIT_REPOSITORIES=	gnunet-go
GIT_REPO.gnunet-go=	https://git.gnunet.org/gnunet-go.git
WRKSRC=			${WRKDIR}/gnunet-go

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.gnunet.org/gnunet-go.git/
COMMENT=	GNUnet implementation in Go
LICENSE=	gnu-agpl-v3

GO_VERSION_DEFAULT=	113
.include "../../mk/bsd.prefs.mk"

GO_SRCPATH=		gnunet
GO_DIST_BASE=		gnunet-go/src/*

.include "../../net/go-dns/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../wip/go-gospel/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
