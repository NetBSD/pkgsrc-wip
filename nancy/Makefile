# $NetBSD$

GITHUB_PROJECT=	nancy
GITHUB_TAG=	v1.0.5
DISTNAME=	v1.0.5
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sonatype-nexus-community/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sonatype-nexus-community/nancy/
COMMENT=	Golang module/dep vulnerability scanner
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/nancy-1.0.5
USE_LANGUAGES=	# none

BUILD_TARGET=	build

.include "go-modules.mk"

#.include "../../devel/go-fsnotify/buildlink3.mk"
#.include "../../devel/go-protobuf/buildlink3.mk"
#.include "../../security/go-crypto/buildlink3.mk"
#.include "../../devel/go-cmp/buildlink3.mk"
#.include "../../devel/go-glog/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
