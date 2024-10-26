# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-1.2.677.0
PKGNAME=	aws-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=aws/}
GITHUB_PROJECT=	session-manager-plugin
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/aws/session-manager-plugin/
COMMENT=	AWS CLI plugin to start/end sessions to your instances
LICENSE=	apache-2.0

USE_TOOLS+=	gmake
BUILD_TARGET=	build-host-native-pkgsrc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pkgsrc_host/* ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pkgsrc_host_plugin/* ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
