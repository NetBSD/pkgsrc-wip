# $NetBSD$

DISTNAME=	jjui-0.4.0.0.20250224
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=idursun/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	9e0d76cf96327de2b40797920cb8e5856cdba27a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/idursun/jjui/
COMMENT=	Text user interface for jj
LICENSE=	mit

DEPENDS+=	jj>=0.21:../../devel/jj

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
