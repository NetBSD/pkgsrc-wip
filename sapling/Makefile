# $NetBSD$

DISTNAME=	sapling-0.2.20231113-145254-995db0d6
PKGNAME=	${DISTNAME:C/-[^-]*-[^-]*$//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_PROJECT=	sapling
GITHUB_TAG=	${DISTNAME:S/sapling-//:S/-99/%2B99/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/sapling
COMMENT=	Scalable, User-Friendly Source Control System
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../wip/folly/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
