# $NetBSD$

GITHUB_PROJECT=	jitsi-meet
DISTNAME=	4276
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/jitsi/jitsi-meet/
COMMENT=	Secure, Simple and Scalable Video Conferences
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/jitsi-meet-${DISTNAME}
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pax

PYTHON_VERSIONS_ACCEPTED=	27

BUILD_DEPENDS+=	npm-[0-9]*:../../lang/npm

BUILD_TARGET=	compile
INSTALL_TARGET=	deploy

INSTALLATION_DIRS+=	share/jitsi-meet
INSTALLATION_DIRS+=	share/jitsi-meet/css

do-configure:
	cd ${WRKSRC} && \
		npm install

post-install:
	cd ${WRKSRC} && \
		${PAX} -rw *.js *.html resources/*.txt \
			connection_optimization favicon.ico fonts images libs \
			static sounds LICENSE lang \
			${DESTDIR}${PREFIX}/share/jitsi-meet && \
		${PAX} -rw css/all.css \
			${DESTDIR}${PREFIX}/share/jitsi-meet/css

.include "../../lang/nodejs/buildlink3.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
