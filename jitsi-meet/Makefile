# $NetBSD$

GITHUB_PROJECT=	jitsi-meet
DISTNAME=	4476
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/jitsi/jitsi-meet/
COMMENT=	Secure, Simple and Scalable Video Conferences
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/jitsi-meet-${DISTNAME}
USE_TOOLS=	gmake tar

BUILD_DEPENDS+=	npm-[0-9]*:../../lang/npm

BUILD_TARGET=	compile
INSTALL_TARGET=	deploy source-package

INSTALLATION_DIRS+=	share/jitsi-meet

do-configure:
	cd ${WRKSRC} && \
		npm install

post-install:
	${RUN} ${TAR} -C ${DESTDIR}${PREFIX}/share -xjf ${WRKSRC}/jitsi-meet.tar.bz2

.include "../../lang/nodejs/buildlink3.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
