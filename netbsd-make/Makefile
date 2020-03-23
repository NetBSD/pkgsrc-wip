# $NetBSD: Makefile,v 1.18 2014/06/29 17:16:25 cheusov Exp $
#

DISTNAME=	bmake-20200212
PKGNAME=	${DISTNAME:S/bmake/nbmake/}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/sjg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility
LICENSE=	original-bsd

WRKSRC=			${WRKDIR}/bmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BOOTSTRAP_ARGS=		-q -o ${OPSYS} --prefix=${PREFIX} \
			--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && exists(/usr/xpg4/bin/sh)
BOOTSTRAP_ARGS+=	--with-defshell=/usr/xpg4/bin/sh
.endif

do-configure:

do-build:
	cd ${WRKDIR} && \
		env ${MAKE_ENV} ${SH} ./bmake/boot-strap ${BOOTSTRAP_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${OPSYS}/bmake ${DESTDIR}${PREFIX}/bin/nbmake
	${INSTALL_MAN} ${WRKSRC}/bmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nbmake.1

.include "../../mk/bsd.pkg.mk"
