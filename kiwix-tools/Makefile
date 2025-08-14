# $NetBSD$

DISTNAME=	kiwix-tools-3.7.0.20250613
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_GITHUB:=kiwix/}
#GITHUB_TAG=	${PKGVERSION_NOREV}
# 3.7.0 does not accept libkiwix 14+
GITHUB_TAG=	acad8a85ab4706ff527cabdaac4635a930f3bdd4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kiwix/kiwix-tools/
COMMENT=	Command-line Kiwix tools
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../wip/docopt.cpp/buildlink3.mk"
.include "../../wip/libzim/buildlink3.mk"
.include "../../wip/libkiwix/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
