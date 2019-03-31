# $NetBSD$

GITHUB_PROJECT=	arduino-builder
DISTNAME=	1.4.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	krz.lasocki@gmail.com
HOMEPAGE=	https://github.com/arduino/arduino-builder/
COMMENT=	Command line tool able to build arduino sketches
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/arduino-builder-1.4.4
USE_LANGUAGES=	c++ go
DEPENDS+= go>=1.8.0:../../lang/go
DEPENDS+= go-errors>=0:../../devel/go-errors
DEPENDS+= go-testify>=0:../../devel/go-testify
DEPENDS+= grpc>=0:../../net/grpc
DEPENDS+= protobuf>=0:../../devel/protobuf
DEPENDS+= go-fsnotify>=:../../devel/go-fsnotify

.include "../../mk/bsd.pkg.mk"
.include "../../lang/go/go-package.mk"
.include "../../devel/go-errors/buildlink3.mk"
.include "../../devel/go-testify/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/go-fsnotify/buildlink3.mk"
