# $NetBSD: Makefile,v 1.1.1.1 2004/03/27 22:59:45 xtraeme Exp $

DISTNAME=	pam_mysql-0.5
PKGNAME=	pam-mysql-0.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pam-mysql/}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://pam-mysql.sourceforge.net/
COMMENT=	PAM module for authenticating with MySQL

WRKSRC=		${WRKDIR}/pam_mysql
USE_GMAKE=	YES
USE_BUILDLINK2=	YES
DOCDIR=		${PREFIX}/share/doc/pam-mysql

post-patch:
	cd ${WRKSRC} && ${GMAKE} clean

do-build:
	${CC} -O -pipe -fpic -DPIC -Wall -I${LOCALBASE}/include -c ${WRKSRC}/pam_mysql.c -o ${WRKSRC}/pam_mysql.o
	${LD} -x --shared -o ${WRKSRC}/pam_mysql.so ${WRKSRC}/pam_mysql.o -lpam -lcrypt -L${LOCALBASE}/lib/mysql -lmysqlclient -L${LOCALBASE}/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/pam_mysql.so ${PREFIX}/lib
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme ${DOCDIR}

.include "../../security/PAM/buildlink2.mk"
.include "../../databases/mysql-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
