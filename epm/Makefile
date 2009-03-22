# $NetBSD: Makefile,v 1.1.1.1 2009/03/22 18:17:56 cheusov Exp $
#

DISTNAME=	epm-4.1-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	misc
MASTER_SITES=	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/epm/4.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/epm/4.1/
COMMENT=	ESP generates software packages from a list of files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		autoconf #gzip:run tar:run

#TEST_TARGET=		test

WRKSRC=			${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

DOCDIR=			${PREFIX}/share/doc/epm

CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--with-docdir=${DOCDIR}
CONFIGURE_ENV+=		STRIP=${TOOLS_PATH.strip}

pre-configure:
	set -e; cd ${WRKSRC}; autoconf;
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/
	${CP} ${.CURDIR}/files/install-sh ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
