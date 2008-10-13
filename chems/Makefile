# $NetBSD: Makefile,v 1.1.1.1 2008/10/13 06:37:44 smoppy Exp $

DISTNAME=	chems-0x03_1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=chems/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	smoppy@gmail.com
HOMEPAGE=	http://chems.sourceforge.net/
COMMENT=	The geekest content helper management system

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

CHEMSDIR=	${PREFIX}/share/chems

do-install:
	${INSTALL_DATA_DIR} ${CHEMSDIR}
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	    ${CHEMSDIR}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d -exec ${INSTALL_DATA} {} \
	    ${CHEMSDIR}/{} \;

.include "../../mk/bsd.pkg.mk"
