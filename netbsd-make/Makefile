# $NetBSD: Makefile,v 1.10 2010/09/30 19:14:57 cheusov Exp $
#

DISTNAME=	bmake-20100911
PKGNAME=	${DISTNAME:S/bmake/nbmake/}
CATEGORIES=	devel
MASTER_SITES=	http://www.crufty.net/ftp/pub/sjg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.crufty.net/help/sjg/bmake.html
COMMENT=	Portable (autoconf) version of NetBSD 'make' utility

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/bmake

USE_FEATURES=		nbcompat

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BOOTSTRAP_ARGS=		-q -o ${OPSYS} --prefix=${PREFIX} \
			--with-default-sys-path=${makesyspath} \
			--mksrc none --sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && exists(/usr/xpg4/bin/sh)
BOOTSTRAP_ARGS+=	--with-defshell=/usr/xpg4/bin/sh
.endif

.if ${OPSYS} == "NetBSD"
makesyspath=	/usr/share/mk
.else
makesyspath=	${PREFIX}/share/mk
DEPENDS+=	bootstrap-mk-files-[0-9]*:../../pkgtools/bootstrap-mk-files
.endif

do-configure:

do-build:
	cd ${WRKDIR} && \
		env ${MAKE_ENV} ${SH} ./bmake/boot-strap ${BOOTSTRAP_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${OPSYS}/bmake ${DESTDIR}${PREFIX}/bin/nbmake
	${INSTALL_MAN} ${WRKSRC}/bmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nbmake.1

.include "../../mk/bsd.pkg.mk"
