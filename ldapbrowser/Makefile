# $NetBSD: Makefile,v 1.1.1.1 2003/09/20 05:54:44 marmfield Exp $
#

DISTNAME=		Browser282b2
PKGNAME=		ldapbrowser-2.8.2b2
PKGREVISION=		# not defined
CATEGORIES=		wip
MASTER_SITES=		http://www-unix.mcs.anl.gov/~gawor/ldapcommon/bin/

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.iit.edu/~gawojar/ldap/
COMMENT=		Java based LDAP browser and editor

WRKSRC=			${WRKDIR}/ldapbrowser

NO_CONFIGURE=		yes
LBE_DIR=		${PREFIX}/lib/ldapbrowser
USE_JAVA=		run

do-build:
	${SED} s%DESTINATION%${LBE_DIR}% ${FILESDIR}/lbe \
		> ${WRKSRC}/lbe.x

do-install:
	${INSTALL_PROGRAM_DIR} ${LDAPBROWSER_HOME}
	${INSTALL_SCRIPT} ${WRKSRC}/lbe.x ${PREFIX}/bin/lbe
	${RM} ${WRKSRC}/lbe.x
	cd ${WRKSRC} && ${PAX} -rwp ma . ${LBE_DIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
