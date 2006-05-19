# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:36 ykomatsu Exp $

DISTNAME=	shoutcast-1-9-2-linux-glibc6
PKGNAME=	shoutcast-1.9.2
CATEGORIES=	audio
MASTER_SITES=	http://www.shoutcast.com/downloads/sc1-9-2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.shoutcast.com/
COMMENT=	Internet Streaming server for MP3 audio

DEPENDS+=	suse_base>=6.4:../../emulators/suse_base

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-1.5Z*-i386 NetBSD-1.[6-9]*-i386
NO_CONFIGURE=	yes
PKG_SYSCONFSUBDIR=	shoutcast

# check-shlibs will fail unless LD_LIBRARY_PATH points to /emul/linux, but
# the binary runs regardless, so..
CHECK_SHLIBS=	no

do-build:

post-build:
	@${SED} -e "s,@LOCALBASE@,${LOCALBASE},g" < ${WRKSRC}/sc_serv.conf > ${WRKSRC}/tmp
	@${SED} -e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g" < ${WRKSRC}/tmp >${WRKSRC}/sc_serv.conf

do-install:
	@${FILESDIR}/install.sh ${WRKDIR}/shoutcast-1-9-2-linux-glibc6 ${LOCALBASE} ${PKG_SYSCONFDIR}

.include "../../emulators/suse_linux/Makefile.application"

.include "../../mk/bsd.pkg.mk"
