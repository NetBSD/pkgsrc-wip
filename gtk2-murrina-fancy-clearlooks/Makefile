# $NetBSD: Makefile,v 1.1 2014/01/31 21:51:09 lokivit Exp $

PKGNAME=	gtk2-murrina-fancy-clearlooks-0.5
VERSION=	0.5
DISTNAME=	MurrinaFancyClearlooks_v${VERSION}
CATEGORIES=	x11 gnome
MASTER_SITES=	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	loki.vt@gmail.com
COMMENT=	Murrine fancy clearlooks themes pack
DEPENDS+=	gtk2-engines-murrine>=0.98.2:../../x11/gtk2-engines-murrine

NO_BUILD=	yes
USE_TOOLS+=	pax
NO_STAGE=	yes

WRKSRC=	${WRKDIR}/MurrinaFancyClearlooks
do-install:
	cd ${WRKSRC} && pax -rw -pp [A-Za-z]* ${DESTDIR}${PREFIX}/share/themes

.include "../../mk/bsd.pkg.mk"
