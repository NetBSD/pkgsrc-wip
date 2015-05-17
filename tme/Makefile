# $NetBSD: Makefile,v 1.12 2015/05/17 20:47:00 phabrics Exp $

DISTNAME=	tme-0.10beta_5
CATEGORIES=	emulators
MASTER_SITES=	http://www.phabrics.com/
EXTRACT_SUFX=   .tar.xz

MAINTAINER=	phabrics@phabrics.com

MAKE_JOBS_SAFE=		no

HOMEPAGE=	http://www.phabrics.com/
COMMENT=	Updated TME to add features like GTK3, NAT, and pthreads
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

CONFLICTS=	tme-[0-9]*

CONFIGURE_ARGS+=	--disable-recode

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
.elif !empty(CC_VERSION:Mgcc-4.[89].*)
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
