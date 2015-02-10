# $NetBSD: Makefile,v 1.4 2015/02/10 05:59:21 phabrics Exp $

DISTNAME=	tme-1.0beta_6
CATEGORIES=	emulators
MASTER_SITES=	http://www.phabrics.com/
EXTRACT_SUFX=   .tar.xz

MAINTAINER=	phabrics@phabrics.com

MAKE_JOBS_SAFE=		no

HOMEPAGE=	http://www.phabrics.com/
COMMENT=	TME modified to add features like GTK3 and NPF NAT
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFLICTS=	tme-[0-9]*

.if (${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	--disable-recode
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-tautological-compare \
			-Wno-sometimes-uninitialized \
			-Wno-unused-function \
			-Wno-unused-parameter \
			-Wno-unused-variable \
			-Wno-sign-compare \
			-Wno-incompatible-pointer-types \
			-Wno-absolute-value
CWRAPPERS_APPEND.cc+=	-Wno-tautological-compare \
			-Wno-sometimes-uninitialized \
			-Wno-unused-function \
			-Wno-unused-parameter \
			-Wno-unused-variable \
			-Wno-sign-compare \
			-Wno-incompatible-pointer-types \
			-Wno-absolute-value
.elif !empty(CC_VERSION:Mgcc-4.8.*)
_WRAP_EXTRA_ARGS.CC+=	-Wno-unused-but-set-variable \
	-Wno-array-bounds \
	-Wno-type-limits \
	-fno-strict-aliasing
CWRAPPERS_APPEND.cc+=	-Wno-unused-but-set-variable \
	-Wno-array-bounds \
	-Wno-type-limits \
	-fno-strict-aliasing

.endif

.include "../../devel/libltdl/convenience.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
