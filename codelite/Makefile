# $NetBSD$

DISTNAME=	codelite-9.1
CATEGORIES=	editors x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=eranif/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eranif/codelite/
COMMENT=	Cross platform C/C++/PHP and Node.js IDE written in C++
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../security/libssh/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
