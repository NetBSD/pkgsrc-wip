# $NetBSD$

PKGNAME=	${GITHUB_PROJECT}-prosody-${DISTNAME}

COMMENT=	Additional plug-ins for Prosody from Jitsi Meet

WRKSRC=		${WRKDIR}/jitsi-meet-${DISTNAME}
USE_TOOLS=	gmake tar

DEPENDS+=	prosody-[0-9]*:../../chat/prosody

INSTALLATION_DIRS+=	share/jitsi-meet-prosody

NO_BUILD=	yes

do-install:
	cd ${WRKSRC}/resources/prosody-plugins && pax -rw -pp . ${DESTDIR}${PREFIX}/share/jitsi-meet-prosody

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../mk/bsd.pkg.mk"
