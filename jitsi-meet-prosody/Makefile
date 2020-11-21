# $NetBSD$

PKGNAME=	${GITHUB_PROJECT}-prosody-${JITSI_MEET_VERSION}

COMMENT=	Additional plug-ins for Prosody from Jitsi Meet

USE_TOOLS=	gmake tar

DEPENDS+=	prosody-[0-9]*:../../chat/prosody

INSTALLATION_DIRS+=	share/jitsi-meet-prosody

NO_BUILD=	yes

do-install:
	cd ${WRKSRC}/resources/prosody-plugins && pax -rw -pp . ${DESTDIR}${PREFIX}/share/jitsi-meet-prosody

.include "../../wip/jitsi-meet/Makefile.common"
.include "../../mk/bsd.pkg.mk"
