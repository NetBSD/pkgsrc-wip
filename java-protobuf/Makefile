# $NetBSD: Makefile,v 1.7 2016/07/09 13:03:43 wiz Exp $

.include "../../devel/protobuf/Makefile.common"

DISTNAME=	protobuf-java-${PROTOBUFVER}
PKGNAME=	java-${DISTNAME:S/-java//}
CATEGORIES+=	java

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Java bindings for protobuf

USE_JAVA=	yes
USE_JAVA2=	yes

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR} MAVEN_OPTS=${MAVEN_OPTS:Q}

MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
#MAVEN_FLAGS+=	--offline
MAVEN_OPTS+=	-Duser.home=${FAKEHOMEDIR}

MAKE_FLAGS+=	JAVA_HOME=${PKG_JAVA_HOME}
MAKE_FLAGS+=	MVN="mvn ${MAVEN_FLAGS}"
MAKE_JOBS_SAFE=	no

pre-build:
	${LN} -s ${PREFIX}/bin/protoc ${WRKSRC}/src

do-build:
	${RUN} cd ${WRKSRC}/java && ${PKGSRC_SETENV} ${MAKE_ENV} ${PREFIX}/bin/mvn ${MAVEN_FLAGS} package

.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
