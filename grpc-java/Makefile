# $NetBSD$

DISTNAME=	grpc-java-1.0.0.pre2
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_GITHUB:=grpc/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/.pre2/-pre2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://grpc.io
COMMENT=	The Java gRPC implementation. HTTP/2 based RPC
LICENSE=	modified-bsd

USE_TOOLS+=	bash

REPLACE_BASH=	gradlew

USE_JAVA=	yes
USE_JAVA2=	yes

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}

USE_LANGUAGES=	c++

do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${BASH} ./gradlew build

.include "../../lang/clang/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
