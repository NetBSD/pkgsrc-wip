# $NetBSD: Makefile,v 1.11 2018/09/13 14:26:07 jperkin Exp $

DISTNAME=	watchman-2022.11.07.00
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://facebook.github.io/watchman/
COMMENT=	Watches files and takes action when they change
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

BUILD_DEFS+=		VARBASE

OWN_DIRS+=		${VARBASE}/run/watchman

.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../wip/edencommon/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
