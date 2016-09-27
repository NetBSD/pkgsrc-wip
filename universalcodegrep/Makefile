# $NetBSD$

DISTNAME=	universalcodegrep-0.2.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=gvansickle/}
GITHUB_PROJECT=	ucg
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gvansickle/ucg/
COMMENT=	Extremely fast grep-like tool for searching source code
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/argp/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
