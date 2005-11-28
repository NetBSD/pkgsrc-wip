# $NetBSD: Makefile,v 1.2 2005/11/28 00:27:28 rillig Exp $

DISTNAME=	runit-1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://smarden.org/runit/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://smarden.org/runit/index.html
COMMENT=	Service monitoring utilities and an init scheme

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
CMDDIR=		${WRKSRC}/command

SERVICEDIR?=	${VARBASE}/spool/service
EXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
DOCS=		package/CHANGES package/COPYING package/README \
		package/THANKS doc/*.html

PLIST_SUBST+=	SERVICEDIR=${SERVICEDIR:Q}
DEINSTALL_FILE=	${WRKDIR}/.DEINSTALL

INSTALLATION_DIRS= man man/man8 sbin share/examples/runit

post-patch:
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/src/conf-cc
	@${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/src/conf-ld

do-build:
	cd ${WRKSRC} && package/compile
	${SED}	"s,@@SERVICEDIR@@,${SERVICEDIR},g"			\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

do-install:
	${INSTALL_PROGRAM} ${CMDDIR}/* ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${SERVICEDIR
	( cd ${WRKSRC}/etc && ${FIND} . -type d ) | while read DIR; do	\
	  ${INSTALL_DATA_DIR} ${EXAMPLEDIR}/$$DIR;			\
        done
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCDIR}
	( cd ${WRKSRC}/etc && ${FIND} . -type f ) | while read FILE; do	\
 	  ${INSTALL_DATA} ${WRKSRC}/etc/$$FILE ${EXAMPLEDIR}/$$FILE;	\
        done

.include "../../mk/bsd.pkg.mk"
