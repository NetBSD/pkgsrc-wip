# $NetBSD: Makefile,v 1.3 2009/11/10 00:40:32 othyro Exp $
#

DISTNAME=	wput-0.6.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wput/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wput.sourceforge.net/
COMMENT=	Wput is a command-line ftp-client that looks like wget

INSTALLATION_DIRS=	${DESTDIR}/bin ${DESTDIR}/${PKGMANDIR}/man1

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wput ${DESTDIR}/${PREFIX}/bin/wput
	${INSTALL_MAN_DIR} ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/wput.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/wput.1

.include "../../mk/bsd.pkg.mk"
