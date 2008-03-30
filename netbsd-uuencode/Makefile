# $NetBSD: Makefile,v 1.8 2008/03/30 00:26:20 cheusov Exp $
#

DISTNAME=	netbsd-uuencode-4.0
PKGREVISION=	1
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME:S/encode/decode/}${EXTRACT_SUFX}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	NetBSD version of uuencode and uudecode utils

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS+=		gmime-[0-9]*

WRKSRC=			${WRKDIR}
BUILD_DIRS=		${DISTNAME} ${DISTNAME:S/encode/decode/}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
USE_BSD_MAKEFILE=	yes

MAKE_ENV+=		MKCATPAGES=no
CPPFLAGS+=		-Dlint
LDFLAGS.Linux+=		-lresolv

.include "../../mk/bsd.pkg.mk"
