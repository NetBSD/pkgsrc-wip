# $NetBSD$

DISTNAME=	# hg package, intentionally left blank
PKGNAME=	openjdk8-openjfx-0
CATEGORIES=	x11
MASTER_SITES=	# hg package, intentionally left blank

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://wiki.openjdk.java.net/display/OpenJFX/Main
COMMENT=	JavaFX application toolkit
#LICENSE=	GPL2 + classpath exception

#DISTFILES=	${DEFAULT_DISTFILES}
#EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

GRADLE_ZIP=		gradle-1.8-bin.zip
SITES.${GRADLE_ZIP}=	https://services.gradle.org/distributions/
DISTFILES+=		${GRADLE_ZIP}
EXTRACT_ONLY+=		${GRADLE_ZIP}

HG_REPOSITORIES=	rt
HG_REPO.rt=		http://hg.openjdk.java.net/openjfx/8u-dev/rt
WRKSRC=			${WRKDIR}/rt

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash pkg-config

MAKE_ENV+=	JAVA_HOME=${PREFIX}/java/openjdk8

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${BASH} ../gradle-1.8/bin/gradle zips

do-install:
	false

.include "../../wip/mk/hg-package.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/openjdk8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
