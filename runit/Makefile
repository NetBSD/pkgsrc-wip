# $NetBSD: Makefile,v 1.6 2006/04/26 23:31:03 akihabara Exp $

DISTNAME=	runit-1.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://smarden.org/runit/

MAINTAINER=	neil@daikokuya.co.uk
HOMEPAGE=	http://smarden.org/runit/index.html
COMMENT=	Service monitoring utilities and an init scheme

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command

SERVICEDIR?=	${VARBASE}/spool/service
OWN_DIRS_PERMS= ${SERVICEDIR} ${ROOT_USER} ${ROOT_GROUP} 0755
EXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
DOCS=		package/CHANGES package/COPYING package/README \
		package/THANKS package/TODO doc/*.html

INSTALLATION_DIRS= ${PKGMANDIR} ${PKGMANDIR}/man8 sbin share/examples/runit

post-patch:
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/src/conf-cc
	@${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/src/conf-ld

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${CMDDIR}/* ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${PREFIX}/${PKGMANDIR}/man8
	cd ${WRKSRC}/etc && ${PAX} -rwppm . ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
