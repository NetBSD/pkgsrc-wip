# $NetBSD: Makefile,v 1.2 2003/09/22 20:43:58 adrian_p Exp $

DISTNAME=	oinkmaster-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.it.su.se/pub/users/andreas/oinkmaster/ \
		http://www.algonet.se/~nitzer/oinkmaster/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.algonet.se/~nitzer/oinkmaster/
COMMENT=	Manage snort rule updates

DEPENDS+=	wget>=1.00:../../net/wget

USE_PERL5=	YES

USE_PKGINSTALL=	YES
USE_BUILDLINK2=	YES

CONF_FILES=	${PREFIX}/share/examples/oinkmaster/oinkmaster.conf \
		${PKG_SYSCONFDIR}/oinkmaster.conf

REPLACE_PERL+=	${WRKSRC}/oinkmaster.pl

do-build:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' < ${WRKSRC}/oinkmaster.pl > \
		${WRKSRC}/oinkmaster
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' < ${WRKSRC}/oinkmaster.conf > \
		${WRKDIR}/oinkmaster.conf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/oinkmaster

	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/oinkmaster
	${INSTALL_DATA} ${WRKDIR}/oinkmaster.conf \
		${PREFIX}/share/examples/oinkmaster
	${INSTALL_SCRIPT} ${WRKSRC}/oinkmaster ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
