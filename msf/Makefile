# $NetBSD: Makefile,v 1.4 2004/06/29 15:49:14 adrian_p Exp $
#

DISTNAME=	framework-2.1
PKGNAME=	msf-2.1
CATEGORIES=	security
MASTER_SITES=	http://www.metasploit.com/tools/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.metasploit.com/
COMMENT=	Platform for developing, testing, and using exploit code

DEPENDS+=	p5-Net-SSLeay>=1.23:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Term-ReadLine>=1.14:../../devel/p5-Term-ReadLine

MSFDIR?=	${PREFIX}/share/msf
MSFDOC?=	${PREFIX}/share/doc/msf
MESSAGE_SUBST+= MSFDIR=${MSFDIR}

PERL5_REQD=	5.6.0
USE_PERL5=	YES
PERL_FILES=	msfcli msfconsole msfdldebug msfencode msflogdump msfpayload \
		msfpayload.cgi msfpescan msfweb
REPLACE_PERL+=	${PERL_FILES}
NO_BUILDLINK=	YES

NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${MSFDIR}
	${INSTALL_DATA_DIR} ${MSFDOC}
	${INSTALL_DATA_DIR} ${MSFDIR}/encoders
	${INSTALL_DATA_DIR} ${MSFDIR}/exploits
	${INSTALL_DATA_DIR} ${MSFDIR}/lib
	${INSTALL_DATA_DIR} ${MSFDIR}/nops
	${INSTALL_DATA_DIR} ${MSFDIR}/payloads
	${INSTALL_DATA_DIR} ${MSFDIR}/payloads/external

	${INSTALL_DATA} ${WRKSRC}/docs/* ${MSFDOC}
	${INSTALL_DATA} ${WRKSRC}/encoders/*.pm ${MSFDIR}/encoders
	${INSTALL_DATA} ${WRKSRC}/exploits/*.pm ${MSFDIR}/exploits

	cd ${WRKSRC}/lib && ${PAX} -rw . ${MSFDIR}/lib

	${INSTALL_DATA} ${WRKSRC}/nops/*.pm ${MSFDIR}/nops
	${INSTALL_DATA} ${WRKSRC}/payloads/*.pm ${MSFDIR}/payloads
	${INSTALL_DATA} ${WRKSRC}/payloads/external/*.py \
		${MSFDIR}/payloads/external

	cd ${WRKSRC}; for file in ${PERL_FILES}; do \
		${INSTALL_SCRIPT} $$file ${MSFDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
