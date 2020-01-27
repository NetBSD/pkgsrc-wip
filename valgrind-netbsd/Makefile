# $NetBSD: Makefile,v 1.22 2016/01/16 20:30:11 ryoon Exp $
#

PKGSRC_USE_SSP=		no

DISTNAME=		valgrind-3.14.0
CATEGORIES=		devel
MASTER_SITES=		http://valgrind.org/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		alnsn@NetBSD.org
HOMEPAGE=		https://valgrind.org/
COMMENT=		Debugging and profiling tools
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Darwin-*-i386 Darwin-*-x86_64 \
			Linux-*-x86_64 \
			Linux-*-i386   \
			Linux-*-arm*   \
			SunOS-*-i386 SunOS-*-x86_64 \
			NetBSD-*-x86_64

USE_TOOLS+=		gmake perl aclocal autoheader automake autoconf
USE_LANGUAGES=		c c++
TEST_TARGET=		regtest

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl.*
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl+=	callgrind/callgrind_annotate.in
REPLACE_FILES.perl+=	callgrind/callgrind_control.in

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:C/arm.*/arm/} == "arm"
PLIST_SUBST+=		VGCONF_ARCH_PRI=arm
.endif

.if ${MACHINE_ARCH} == "i386"
PLIST_SUBST+=		VGCONF_ARCH_PRI=x86
.endif

.if ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=		VGCONF_ARCH_PRI=amd64
#PLIST_SUBST+=		VGCONF_ARCH_SEC=x86
CONFIGURE_ARGS+=	--enable-only64bit
.endif

#CFLAGS+=	-fsanitize-coverage=trace-pc

CFLAGS+=		-O0 -g -ggdb
CXXFLAGS+=		-O0 -g -ggdb
INSTALL_UNSTRIPPED=	yes
BUILDLINK_TRANSFORM+=	rm:-s

#CFLAGS+=		-fsanitize=address
#LDFLAGS+=		-fsanitize=address

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../mk/bsd.pkg.mk"
