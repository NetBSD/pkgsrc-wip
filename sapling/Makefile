# $NetBSD$

DISTNAME=	sapling-0.2.20241203-120811+a2174689
PKGNAME=	${DISTNAME:C/-12/.12/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_PROJECT=	sapling
GITHUB_TAG=	${DISTNAME:S/sapling-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/sapling
COMMENT=	Scalable, User-Friendly Source Control System
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	rust-[0-9]*:../../lang/rust
TOOL_DEPENDS+=	yarn-[0-9]*:../../devel/yarn
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

CPPFLAGS+=	-I${PREFIX}/include/node

WRKSRC=		${WRKDIR}/${DISTNAME:S/+/-/}
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pkg-config

do-build:
	cd ${WRKSRC}/eden/scm && gmake oss

#.include "../../devel/cmake/build.mk"
#.include "../../wip/folly/buildlink3.mk"
#.include "../../devel/gflags/buildlink3.mk"
#.include "../../devel/google-glog/buildlink3.mk"
#.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../lang/nodejs/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
