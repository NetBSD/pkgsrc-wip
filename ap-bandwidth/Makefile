# $NetBSD: Makefile,v 1.2 2003/04/27 10:41:40 cjep Exp $
#

DISTNAME=	ap-bandwidth-2.0.3
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cohprog.com/pub/apache/module/1.3.0/ \
		http://www.cohprog.com/v3/bandwidth/
DISTFILES=	mod_bandwidth.c doc-en.html

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cohprog.com/mod_bandwidth.html
COMMENT=	Bandwidth throttling module for Apache 1.3.x

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
USE_PERL5=	build	# for "apxs"

DIST_SUBDIR=	${PKGNAME}

EXTRACT_CMD=	${GZIP_CMD} -dc >${WRKDIR}/${DISTNAME} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

# the sed rule below cleans up the docs so that it's not dependent on the
# homepage's structure (there's no "detached" docs available).
do-extract: ${WRKDIR}
	@${CP} ${_DISTDIR}/mod_bandwidth.c ${WRKDIR}
	@${SED} -e '/JavaScript/,/476/d;/cleanlink/,/dead links/d;/td>/,/TABLE>/d' \
		${_DISTDIR}/doc-en.html >${WRKDIR}/mod_bandwidth.html

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_bandwidth.so *.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_bandwidth.so
	${INSTALL_DATA} ${WRKSRC}/mod_bandwidth.html ${PREFIX}/share/doc/

.include "../../mk/bsd.pkg.mk"
