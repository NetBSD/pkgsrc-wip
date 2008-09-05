# $NetBSD: Makefile,v 1.12 2008/09/05 09:53:13 cheusov Exp $
#

DISTNAME=	paexec-0.10.0
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paexec/} \
		http://mova.org/~cheusov/pub/paexec/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/paexec
COMMENT=	Parallel executor, distributes tasks over network

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

.include "../../mk/bsd.prefs.mk"

SUPPORTED_SYSTEM=	0
.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Linux"
SUPPORTED_SYSTEM=	1
.endif

.if ${SUPPORTED_SYSTEM} == "0"
CPPFLAGS+=		-DNO_PORTABHACKS_H=1 -DHAVE_CONFIG_H=1
pre-build:
	${ECHO} '#include <getopt.h>' > ${WRKSRC}/config.h
.endif

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
	${INSTALL_SCRIPT} ${WRKSRC}/examples/1_div_X/1_div_X_cmd \
		${DESTDIR}${PKGEGDIR}/1_div_X/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/1_div_X/1_div_X_run \
		${DESTDIR}${PKGEGDIR}/1_div_X/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/make_package/make_package_cmd* \
		${DESTDIR}${PKGEGDIR}/make_package/
	${INSTALL_DATA} ${WRKSRC}/examples/make_package/make_package_tasks \
		${DESTDIR}${PKGEGDIR}/make_package/

.if ${SUPPORTED_SYSTEM} == "0"
.include "../../pkgtools/libnbcompat/inplace.mk"
.endif

.include "../../wip/libmaa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
