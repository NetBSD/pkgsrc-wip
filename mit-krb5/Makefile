# $NetBSD: Makefile,v 1.1.1.1 2003/07/30 17:08:55 jeremy-c-reed Exp $

DISTNAME=		krb5-1.3
PKGNAME=		mit-${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		security
MASTER_SITES=		# empty
# has 1.2.8
#MASTER_SITES=	http://www.crypto-publish.org/dist/mit-kerberos5/
#MASTER_SITES+=	http://www.mirrors.wiretapped.net/security/cryptography/apps/kerberos/krb5-mit/unix/
# XXX if using above MASTER_SITES then fix EXTRACT_SUFX and get rid of FETCH below
EXTRACT_SUFX=		.tar

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://web.mit.edu/kerberos/www/
COMMENT=		MIT Kerberos 5 authentication system

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

CONFLICTS=		kth-krb4-[0-9]*

YACC=			bison -y
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-shared

# XXX do we care?
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DOWNLOAD=		http://web.mit.edu/network/kerberos-form.html

INTERACTIVE_STAGE=	fetch

_FETCH_MESSAGE= \
	    ${ECHO} "==============================================================="; \
	    ${ECHO} "  MIT Kerberos V5 source code (${DISTNAME}${EXTRACT_SUFX}) can be fetched"; \
	    ${ECHO} "  into ${DISTDIR} from"; \
	    ${ECHO} "  ${DOWNLOAD}."; \
	    ${ECHO} "==============================================================="

post-extract:
	cd ${WRKDIR} && ${PAX} -O -rzf ${WRKDIR}/${DISTNAME}.tar.gz

#.include "../../mk/yacc.mk"

.include "../../mk/bsd.pkg.mk"
