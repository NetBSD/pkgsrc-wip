# $NetBSD: Makefile,v 1.2 2011/09/14 14:44:57 ryo-on Exp $
#

DISTNAME=	firefox-${FIREFOX_VER}
PKGNAME=	firefox-bin-${FIREFOX_VER}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/linux-i686/en-US/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Web browser with support for extensions
LICENSE=	mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

FIREFOX_VER=	3.6.22

WRKSRC=		${WRKDIR}/firefox
USE_LANGUAGES=	# none

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	gtk2 locale alsa
EMUL_REQD=		suse>=11.3

INSTALLATION_DIRS=	bin \
			opt

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${CP} -r ${WRKSRC} ${DESTDIR}${PREFIX}/opt/firefox-${FIREFOX_VER}
	${LN} -sf ${PREFIX}/opt/firefox-${FIREFOX_VER}/firefox \
		${DESTDIR}${PREFIX}/bin/firefox-${FIREFOX_VER}

.include "../../mk/bsd.pkg.mk"
