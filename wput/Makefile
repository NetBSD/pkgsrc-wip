# $NetBSD: Makefile,v 1.7 2010/04/11 08:58:16 obache Exp $
#

DISTNAME=	wput-0.6.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wput/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wput.sourceforge.net/
COMMENT=	Wput is a command-line ftp-client that looks like wget
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wput ${DESTDIR}/${PREFIX}/bin/wput
	${INSTALL_MAN} ${WRKSRC}/doc/wput.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/wput.1

.include "../../mk/bsd.pkg.mk"
