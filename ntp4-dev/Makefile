# $NetBSD: Makefile,v 1.1.1.1 2003/08/07 01:50:59 adrian_p Exp $
#

DISTNAME=	ntp-4.1.80-rc1
PKGNAME=	ntp-dev-4.1.80-rc1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.ntp.org/
COMMENT=	Network Time Protocol Version 4 (Development Branch)

CONFLICTS=	ntp-[0-9]*

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

DOCDIR=		${PREFIX}/share/doc/html
EXAMPLESDIR=	${PREFIX}/share/examples

post-install:
	cd ${WRKSRC} &&						\
	    ${PAX} -rw -s "/html/ntp4/" html ${DOCDIR};	\
	    ${PAX} -rw -s "/conf/ntp4/" conf ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} -R ${SHAREMODE} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${FIND} ${DOCDIR}/ntp4 -type d | ${XARGS} ${CHMOD} a+x
	${CHMOD} a+x ${EXAMPLESDIR}/ntp4

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
