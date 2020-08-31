# $NetBSD$

GITHUB_PROJECT=	jitsi-meet
DISTNAME=	3858
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jitsi/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/jitsi/jitsi-meet/
COMMENT=	Secure, Simple and Scalable Video Conferences
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/jitsi-meet-3858
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake

PYTHON_VERSIONS_ACCEPTED=	27

do-configure:
	cd ${WRKSRC} && \
		npm install

BUILD_DEPENDS+=	npm-[0-9]*:../../lang/npm

.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/python/tool.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
