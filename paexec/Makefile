# $NetBSD: Makefile,v 1.1 2008/01/24 20:54:19 cheusov Exp $
#

DISTNAME=	paexec-0.6.0
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paexec/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/paexec
COMMENT=	Parallel executor, distributes tasks over network

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
PKGEGDIR=		${PREFIX}/share/examples/${PKGBASE}
EGLIST=			cc_wrapper all_substr toupper

INSTALLATION_DIRS+=	${PKGDOCDIR} ${PKGEGDIR}
.for d in ${EGLIST}
INSTALLATION_DIRS+=	${PKGEGDIR}/${d}
.endfor

DOC_FILES=		README NEWS ChangeLog

MAKE_ENV+=		PREFIX=${PREFIX}
MAKE_ENV+=		MKCATPAGES=no
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/examples/all_substr/all_substr_cmd \
		${DESTDIR}${PKGEGDIR}/all_substr/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/all_substr/all_substr_run \
		${DESTDIR}${PKGEGDIR}/all_substr/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/toupper/toupper_cmd \
		${DESTDIR}${PKGEGDIR}/toupper/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/toupper/toupper_run \
		${DESTDIR}${PKGEGDIR}/toupper/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/cc_wrapper/cc_wrapper_cmd \
		${DESTDIR}${PKGEGDIR}/cc_wrapper/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/cc_wrapper/cc_wrapper_run \
		${DESTDIR}${PKGEGDIR}/cc_wrapper/
	${INSTALL_DATA} ${WRKSRC}/examples/cc_wrapper/func*.c \
		${DESTDIR}${PKGEGDIR}/cc_wrapper/

.include "../../wip/libmaa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
