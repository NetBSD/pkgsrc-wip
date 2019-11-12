# $NetBSD$

DISTNAME=	gif2png-master
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.com/esr/gif2png/-/archive/master/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/esr/gif2png/
COMMENT=	Convert GIFs to PNG format
LICENSE=	modified-bsd

GO_SRCPATH=	gitlab.com/esr/gif2png
GO_DIST_BASE=	gif2png-master

.include "../../security/go-crypto/buildlink3.mk"
.include "../../devel/go-sys/buildlink3.mk"

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
