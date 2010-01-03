# $NetBSD: Makefile,v 1.25 2010/01/03 11:34:44 cheusov Exp $
#

DISTNAME=	paexec-0.14.0
CATEGORIES=	parallel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paexec/} \
		http://mova.org/~cheusov/pub/paexec/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/paexec
COMMENT=	Parallel executor, distributes tasks over network

LICENSE=		mit

DEPENDS+=		runawk>=0.16.0:../../wip/runawk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
USE_BSD_MAKEFILE=	yes

TEST_TARGET=		test

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
PKGEGDIR=		${PREFIX}/share/examples/${PKGBASE}

AUTO_MKDIRS=		yes

DOC_FILES=		README NEWS ChangeLog

MAKE_ENV+=		PREFIX=${PREFIX}
MAKE_ENV+=		MKCATPAGES=no
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		LDADD=${LIBS:Q}

REPLACE_AWK+=		examples/1_div_X/1_div_X_cmd \
			examples/all_substr/all_substr_cmd \
			examples/make_package/make_package_cmd \
			examples/toupper/toupper_cmd \
			examples/broken_echo/transport_broken_echo \
			tests/big_result_cmd \
			tests/transport_broken_rnd \
			examples/make_package/make_package_cmd__*
REPLACE_SH+=		examples/cc_wrapper/cc_wrapper_cmd \
			examples/broken_echo/transport_broken_echo2

post-install:
	${INSTALL_SCRIPT} ${.CURDIR}/files/paexec_reorder ${DESTDIR}${PREFIX}/bin
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
	${INSTALL_SCRIPT} ${WRKSRC}/examples/1_div_X/1_div_X_cmd \
		${DESTDIR}${PKGEGDIR}/1_div_X/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/1_div_X/1_div_X_run \
		${DESTDIR}${PKGEGDIR}/1_div_X/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/make_package/make_package_cmd* \
		${DESTDIR}${PKGEGDIR}/make_package/
	${INSTALL_DATA} ${WRKSRC}/examples/make_package/make_package_tasks \
		${DESTDIR}${PKGEGDIR}/make_package/

.include "../../devel/libmaa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
