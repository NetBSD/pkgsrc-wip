# $NetBSD: Makefile,v 1.1.1.1 2008/09/28 13:40:52 cheusov Exp $
#

DISTNAME=	netbsd-send-pr-20080927
CATEGORIES=	sysutils
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	NetBSD version of send-pr

HAS_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS=		--prefix=${PREFIX}

MANDIR1=		${PKGMANDIR}/man1
CATEGORDIR=		lib/gnats

INSTALLATION_DIRS=	bin ${MANDIR1} ${CATEGORDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/send-pr ${DESTDIR}${PREFIX}/bin/nbsend-pr
#	${INSTALL_SCRIPT} ${WRKSRC}/install-sid ${DESTDIR}${PREFIX}/bin/nb
	${INSTALL_MAN} ${WRKSRC}/send-pr.1 ${DESTDIR}${PREFIX}/${MANDIR1}/nbsend-pr.1
	${INSTALL_DATA} ${WRKSRC}/categories ${DESTDIR}${PREFIX}/${CATEGORDIR}/netbsd

.include "../../mk/bsd.pkg.mk"
