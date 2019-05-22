# $NetBSD: Makefile,v 1.7 2012/09/28 21:24:31 asau Exp $

DISTNAME=	util-linux-2.12r
VERSION=	2.12r
PKGNAME=	ddate-${VERSION}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/misc/} \
		http://www.kernel.org/pub/linux/utils/util-linux/ \
		ftp://ftp.fr.kernel.org/pub/linux/utils/util-linux/

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://freshmeat.net/projects/util-linux/
COMMENT=		The enhanced Discordian date program
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFLICTS+=		util-linux-[0-9]*
DOCDIR=			${PREFIX}/share/doc/ddate
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/ddate

do-build:
	cd ${WRKSRC}/misc-utils && gmake ddate

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/misc-utils/ddate ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/misc-utils/ddate.doc ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/misc-utils/ddate.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
