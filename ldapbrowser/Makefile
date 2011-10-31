# $NetBSD: Makefile,v 1.16 2011/10/31 13:43:50 noud4 Exp $
#

DISTNAME=		Browser282b2
PKGNAME=		ldapbrowser-2.8.2b2
PKGREVISION=		1
WRKSRC=			${WRKDIR}/ldapbrowser
CATEGORIES=		sysutils
MASTER_SITES=		http://www-unix.mcs.anl.gov/~gawor/ldapcommon/bin/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-unix.mcs.anl.gov/~gawor/ldap/
COMMENT=		Java based LDAP browser and editor

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_JAVA=		run
USE_JAVA2=		yes
USE_TOOLS+=		pax

LBE_DIR=		${PREFIX}/lib/ldapbrowser

do-build:
	${SED} s%DESTINATION%${LBE_DIR}% ${WRKSRC}/lbe.sh \
		> ${WRKSRC}/lbe.sh.x
	${MV} ${WRKSRC}/lbe.sh.x ${WRKSRC}/lbe.sh
	${CHMOD} a+x ${WRKSRC}/lbe.sh

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${LBE_DIR}
	cd ${WRKSRC} && pax -rwp ma . ${DESTDIR}${LBE_DIR}
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${LN} -s ${DESTDIR}${LBE_DIR}/lbe.sh ${DESTDIR}${PREFIX}/bin/lbe

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
