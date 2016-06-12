# $NetBSD$

DISTNAME=	filter_audio-0.0.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=irungentoo/}

GIT_REPOSITORIES=	filter_audio
GIT_REPO.filter_audio=	http://github.com/irungentoo/filter_audio.git
WRKSRC=			${WRKDIR}/filter_audio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/irungentoo/filter_audio/
COMMENT=	Easy to use audio filtering library made from webrtc code
LICENSE=	modified-bsd

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
