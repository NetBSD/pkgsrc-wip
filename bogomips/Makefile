# $NetBSD: Makefile,v 1.8 2012/09/24 17:14:37 asau Exp $
#

DISTNAME=	bogomips-1.4.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://djwong.org/programs/bogomips/

MAINTAINER=	schaecsn@gmx.net
HOMEPAGE=	http://djwong.org/programs/bogomips/
COMMENT=	Unscientific measurement of CPU speed
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/${PKGBASE}

PKG_OPTIONS_VAR=		PKG_OPTIONS.bogomips
PKG_SUPPORTED_OPTIONS=		# empty
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=		bogomips-pentium # Version for pentium and above,
PKG_SUGGESTED_OPTIONS+=		bogomips-pentium # disable for i[34]86.
.endif
.if ${MACHINE_ARCH} == "arm"
PKG_OPTIONS_OPTIONAL_GROUPS+=	arm
# Portable bogomips version will be build for ARM, except for ARM IPAQ or ARM
# Shark architectures, if the corresponding option is set.
PKG_OPTIONS_GROUP.arm=		bogomips-arm-ipaq bogomips-arm-shark
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbogomips-pentium)
BUILD_TARGET.i386=	bogo586
BUILD_TARGET.x86_64=	bogo586
.else
BUILD_TARGET.i386=	bogo386
BUILD_TARGET.x86_64=	bogo386
.endif
BUILD_TARGET.alpha=	bogoAlpha
BUILD_TARGET.sparc64=	bogoSparc64
BUILD_TARGET.sparc=	bogoSparc
BUILD_TARGET.powerpc=	bogoPPC
BUILD_TARGET.hppa=	bogoParisc
BUILD_TARGET.ia64=	bogoia64
.if !empty(PKG_OPTIONS:Mbogomips-arm-ipaq)
BUILD_TARGET.arm=	bogoarm-ipqq
.endif
.if !empty(PKG_OPTIONS:Mbogomips-arm-shark)
BUILD_TARGET.arm=	bogoarm-shark
.endif

BUILD_TARGET=		${BUILD_TARGET.${MACHINE_ARCH}:Ubogoport}

INSTALLATION_DIRS+=	share/doc/bogomips
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_TARGET:Q} ${DESTDIR}${PREFIX}/bin/bogomips
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bogomips


.include "../../mk/bsd.pkg.mk"
