# $NetBSD: Makefile,v 1.6 2003/09/21 13:19:13 marmfield Exp $
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

USE_BUILDLINK2=		yes
NO_CONFIGURE=		yes
LBE_DIR=		${PREFIX}/lib/ldapbrowser
USE_JAVA=		run
USE_JAVA2=		yes

do-build:
	${SED} s%DESTINATION%${LBE_DIR}% ${WRKSRC}/lbe.sh \
		> ${WRKSRC}/lbe.sh.x
	${MV} ${WRKSRC}/lbe.sh.x ${WRKSRC}/lbe.sh
	${CHMOD} a+x ${WRKSRC}/lbe.sh

do-install:
	${INSTALL_PROGRAM_DIR} ${LBE_DIR}
	cd ${WRKSRC} && ${PAX} -rwp ma . ${LBE_DIR}
	ln -s ${LBE_DIR}/lbe.sh ${PREFIX}/bin/lbe

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
