# $NetBSD$

PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}

COMMENT=	Secure, Simple and Scalable Video Conferences

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

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../lang/nodejs/buildlink3.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
