# $NetBSD: Makefile,v 1.1.1.1 2005/04/21 14:39:45 poppnk Exp $
#

DISTNAME=		jamvm-1.3.0
CATEGORIES=		wip lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jamvm/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jamvm.sourceforge.net/
COMMENT=		Compact Java Virtual Machine

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jamvm ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/jni.h ${PREFIX}/include/
	${INSTALL_DATA_DIR} ${PREFIX}/share/jamvm/classes/
	unzip -o ${WRKSRC}/lib/classes.zip -d ${PREFIX}/share/jamvm/classes/
	
.include "../../mk/bsd.pkg.mk"
