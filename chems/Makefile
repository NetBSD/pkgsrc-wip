# $NetBSD: Makefile,v 1.5 2012/09/24 17:35:29 asau Exp $

DISTNAME=	chems-0x04
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=chems/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://chems.sourceforge.net/
COMMENT=	The geekest content helper management system
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

CHEMSDIR=	${DESTDIR}${PREFIX}/share/chems

do-install:
	${INSTALL_DATA_DIR} ${CHEMSDIR}
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	    ${CHEMSDIR}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d -exec ${INSTALL_DATA} {} \
	    ${CHEMSDIR}/{} \;

.include "../../mk/bsd.pkg.mk"
