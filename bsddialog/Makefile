# $NetBSD$

BSDDIALOG_VERSION=	1.0.4

DISTNAME=	bsddialog-${BSDDIALOG_VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITLAB:=khorben/}
GITLAB_PROJECT=	bsddialog
GITLAB_TAG=	1.0.4+khorben

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://gitlab.com/khorben/bsddialog
COMMENT=	TUI Dialogs and Widgets
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/bsddialog-${GITLAB_TAG}

USE_CURSES=	wide

.include "../../mk/bsd.prefs.mk"

.if ${SHLIB_TYPE} == "dylib"
SOEXT=		dylib
LDFLAGS+=	-Wl,-install_name,${PREFIX}/lib/libbsddialog.${BSDDIALOG_VERSION}.${SOEXT}
.else
SOEXT=		so
.endif

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	SOEXT=${SOEXT}
AUTO_MKDIRS=	yes

.if ${SHLIB_TYPE} == "dylib"
post-install:
	${LN} -sf libbsddialog.${BSDDIALOG_VERSION}.${SOEXT} \
		${DESTDIR}${PREFIX}/lib/libbsddialog.${SOEXT}
	${MV} ${DESTDIR}${PREFIX}/lib/libbsddialog.${SOEXT}.${BSDDIALOG_VERSION} \
		${DESTDIR}${PREFIX}/lib/libbsddialog.${BSDDIALOG_VERSION}.${SOEXT}
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
