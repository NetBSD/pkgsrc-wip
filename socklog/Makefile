# $NetBSD: Makefile,v 1.1 2006/04/25 13:34:36 akihabara Exp $

DISTNAME=	socklog-2.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://smarden.org/socklog/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://smarden.org/socklog/index.html
COMMENT=	Small and secure replacement for syslogd

WRKSRC=		${WRKDIR}/admin/${DISTNAME}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
DOCS=		package/CHANGES package/COPYING package/README \
		doc/*.html

post-patch:
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/src/conf-cc
	@${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/src/conf-ld

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
