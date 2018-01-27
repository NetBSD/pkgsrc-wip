# $NetBSD: Makefile,v 1.10 2012/11/23 22:44:44 othyro Exp $

DISTNAME=	slrn-pre1.0.0-26
PKGNAME=	slrn-pre1.0.0-26
CONFLICTS=	slrn-pl-[0-9]* slrn-[0-9]*
LICENSE=	gnu-gpl-v2
#PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.jedsoft.org/snapshots/

MAINTAINER=	aniou@smutek.pl
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-inews --with-slrnpull --enable-spool \
			--enable-grouplens --with-libdir=${PREFIX}/lib/slrn \
			--enable-mid-cache \
			--with-slang=${PREFIX} \
			--with-slanglib=-lslang2 \
			--with-slanginc=slang2/slang.h \
			--with-localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../mk/bsd.prefs.mk"

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
.if ${OPSYS} == "NetBSD" && ${OS_VERSION} == "1.3.2"
CONFIGURE_ENV+=		INSTALL=/usr/bin/install
.endif

# at least NetBSD
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-non-gnu-iconv
.endif

LDFLAGS.Linux+=	-ldl

.include "../../devel/libslang2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
