# $NetBSD$

DISTNAME=	laser-1.7.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmattaa/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/jmattaa/laser/
COMMENT=	Basically ls(1) but readable
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

CMAKE_CONFIGURE_ARGS+=	-DLUA_SCRIPTS_INSTALL_PATH=${PREFIX}/share/laser

.include "../../devel/cmake/build.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
