# $NetBSD: Makefile,v 1.3 2004/08/17 18:32:15 tvierling Exp $
#

DISTNAME=		${SILC_TOOLKIT_DISTNAME}
CATEGORIES=		chat devel security
MASTER_SITES=		http://www.silcnet.org/download/toolkit/sources/ \
			ftp://ftp.silcnet.org/silc/toolkit/sources/ \
			http://www.fi.silcnet.org/download/toolkit/sources/ \
			ftp://ftp.au.silcnet.org/pub/silcnet/toolkit/sources/ \
			http://www.at.silcnet.org/download/toolkit/sources/
EXTRACT_SUFX=		${SILC_TOOLKIT_EXTRACT_SUFX}

MAINTAINER=		oherrala@ee.oulu.fi
HOMEPAGE=		http://www.silcnet.org/
COMMENT=                Toolkit for the Secure Internet Live Conferencing (SILC) protocol

.include "../../wip/silc-toolkit/Makefile.common"

# There is some problems with pkgviews installation.. need to investigate
#PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_GNU_TOOLS+=make
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/silc-toolkit/libsilc.la
LIBTOOL_LA_FILES+=	lib/silc-toolkit/libsilcclient.la

CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/share/silc-toolkit/etc
CONFIGURE_ARGS+=	--with-helpdir=${PREFIX}/share/silc-toolkit/help
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silc-toolkit
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/silc-toolkit/modules
CONFIGURE_ARGS+=	--with-logsdir=${PREFIX}/share/silc-toolkit/logs
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/silc-toolkit
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/silc-toolkit
CONFIGURE_ARGS+=	--enable-shared=yes --enable-static=yes
CONFIGURE_ARGS+=	--without-libtoolfix
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--without-irssi
CONFIGURE_ARGS+=	--without-silcd

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# Assembler optimizations.
#
.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

# If you want to debug silc-toolkit, uncomment this.
#
CONFIGURE_ARGS+=	--enable-debug

#PLIST_SRC+=		${PKGDIR}/PLIST

PTHREAD_OPTS+=		native optional
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-pthreads
.else
CONFIGURE_ARGS+=	--with-pthreads
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
