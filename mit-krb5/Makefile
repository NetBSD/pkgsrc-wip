# $NetBSD: Makefile,v 1.7 2004/03/04 23:13:59 jeremy-c-reed Exp $

DISTNAME=		krb5-1.3.1
PKGNAME=		mit-${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		security
# Official site has different download (tar with tar.gz inside it)
# and it is an interactive install so use these mirrors instead
#MASTER_SITES=		# empty
MASTER_SITES=	http://www.crypto-publish.org/dist/mit-kerberos5/
MASTER_SITES+=	http://www.mirrors.wiretapped.net/security/cryptography/apps/kerberos/krb5-mit/unix/
# XXX if using above MASTER_SITES then fix EXTRACT_SUFX and get rid of FETCH below
#EXTRACT_SUFX=		.tar

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://web.mit.edu/kerberos/www/
COMMENT=		MIT Kerberos 5 authentication system

CONFLICTS+=		heimdal-[0-9]*
CONFLICTS+=		kth-krb4-[0-9]*

.if !exists(/usr/bin/yacc)
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
YACC=			${LOCALBASE}/bin/bison -y
.endif

YACC=			bison -y
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-shared
MAKE_ENV+=		ROOT_USER=${ROOT_USER}

# XXX do we care?
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

#DOWNLOAD=		http://web.mit.edu/network/kerberos-form.html

#INTERACTIVE_STAGE=	fetch

#_FETCH_MESSAGE= \
#	    ${ECHO} "==============================================================="; \
#	    ${ECHO} "  MIT Kerberos V5 source code (${DISTNAME}${EXTRACT_SUFX}) can be fetched"; \
#	    ${ECHO} "  into ${DISTDIR} from"; \
#	    ${ECHO} "  ${DOWNLOAD}."; \
#	    ${ECHO} "==============================================================="

# XXX Only need this post-extract target when using the download
# XXX from the interactive fetch.
#post-extract:
#	cd ${WRKDIR} && ${PAX} -O -rzf ${WRKDIR}/${DISTNAME}.tar.gz

#.include "../../mk/yacc.mk"

.include "../../mk/bsd.pkg.mk"
