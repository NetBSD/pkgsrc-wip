# $NetBSD: Makefile,v 1.8 2015/09/07 19:16:42 jonthn Exp $

DISTNAME=	Bear-3.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rizsotto/}
# post 3.1.4, contains with fix for fmtlib 11
GITHUB_TAG=	8afeafe61299c87449023d63336389f159b55808

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rizsotto/Bear
COMMENT=	Tool to generate compilation database
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SUBST+=	LIBEXT=dylib
.else
PLIST_SUBST+=	LIBEXT=so
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/grpc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
