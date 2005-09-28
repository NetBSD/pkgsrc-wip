# $NetBSD: Makefile,v 1.3 2005/09/28 14:24:41 rillig Exp $
#

DISTNAME=		jamvm-1.3.2
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
