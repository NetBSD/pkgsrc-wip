# $NetBSD$

DISTNAME=	TriforceAFL-0.0.${SNAPSHOT}
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=nccgroup/}
GITHUB_TAG=	2a8ed329233a921044c903222fc3aa029ef68c69

SNAPSHOT=	2017.06.01

MAINTAINER=	vishnu@akulpillai.com
HOMEPAGE=	https://github.com/nccgroup/TriforceAFL/
COMMENT=	AFL/QEMU fuzzing with full-system emulation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd
LICENSE+=	AND apache-2.0

USE_TOOLS=	bash:run bison gmake perl:build pkg-config makeinfo
REPLACE_SH+=	afl-plot
REPLACE_BASH+=	afl-cmin

WRKSRC=		${WRKDIR}/TriforceAFL-${GITHUB_TAG}

PYTHON_VERSIONS_ACCEPTED=	27 # not ported as of 2017.06.01

AFLPREFIX=	${PREFIX}/${PKGBASE}

MAKE_FLAGS=	PREFIX=${AFLPREFIX}

post-install:
	${RUN} cd ${WRKSRC} && \
		${INSTALL_PROGRAM} afl-qemu-system-trace \
			${DESTDIR}${AFLPREFIX}/bin
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} config.h \
			${DESTDIR}${AFLPREFIX}
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} types.h \
			${DESTDIR}${AFLPREFIX}
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA_DIR} ${DESTDIR}${AFLPREFIX}/share/pc-bios
	${RUN} cd ${WRKSRC}/qemu_mode/qemu/pc-bios/ && \
		pax -wr * ${DESTDIR}${AFLPREFIX}/share/pc-bios

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
