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

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
