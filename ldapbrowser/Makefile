# $NetBSD: Makefile,v 1.9 2005/04/11 21:13:39 tvierling Exp $
#

DISTNAME=		Browser282b2
PKGNAME=		ldapbrowser-2.8.2b2
WRKSRC=			${WRKDIR}/ldapbrowser
CATEGORIES=		wip sysutils
MASTER_SITES=		http://www-unix.mcs.anl.gov/~gawor/ldapcommon/bin/

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.iit.edu/~gawojar/ldap/
COMMENT=		Java based LDAP browser and editor

USE_JAVA=		run
USE_JAVA2=		yes

NO_CONFIGURE=		yes

LBE_DIR=		${PREFIX}/lib/ldapbrowser

do-build:
	${SED} s%DESTINATION%${LBE_DIR}% ${WRKSRC}/lbe.sh \
		> ${WRKSRC}/lbe.sh.x
	${MV} ${WRKSRC}/lbe.sh.x ${WRKSRC}/lbe.sh
	${CHMOD} a+x ${WRKSRC}/lbe.sh

do-install:
	${INSTALL_PROGRAM_DIR} ${LBE_DIR}
	cd ${WRKSRC} && ${PAX} -rwp ma . ${LBE_DIR}
	${LN} -s ${LBE_DIR}/lbe.sh ${PREFIX}/bin/lbe

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
